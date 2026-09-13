// Fill out your copyright notice in the Description page of Project Settings.

#include "Ollama.h"
#include "HttpModule.h"
#include "Json.h"
#include "JsonUtilities.h"

AOllama::AOllama()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AOllama::BeginPlay()
{
    Super::BeginPlay();

    LastReply = TEXT("hello");
}

FString AOllama::GetAIResponse() const
{
    return TEXT("Hello from C++");
}
FString AOllama::SendMessage( const FString& UserMessage)
{
    UE_LOG(LogTemp, Warning, TEXT("SendMessage Called"));
        LastReply = TEXT("Sending...");
        ActiveRequest = FHttpModule::Get().CreateRequest();
        ActiveRequest->SetURL(TEXT("http://localhost:11434/api/chat"));
        ActiveRequest->SetVerb(TEXT("POST"));
        ActiveRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        UE_LOG(LogTemp, Warning, TEXT("Request Created"));
        TSharedPtr<FJsonObject> RequestObj = MakeShareable(new FJsonObject);
        RequestObj->SetStringField(TEXT("model"), TEXT("phi3:mini"));
        RequestObj->SetBoolField(TEXT("stream"), false);
        TArray<TSharedPtr<FJsonValue>> Messages;
        TSharedPtr<FJsonObject> MessageObj = MakeShareable(new FJsonObject);
        MessageObj->SetStringField(TEXT("role"), TEXT("user"));
        MessageObj->SetStringField(TEXT("content"), UserMessage);
        Messages.Add(MakeShareable(new FJsonValueObject(MessageObj)));
        RequestObj->SetArrayField(TEXT("messages"),Messages);
        FString RequestBody;
        TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
        FJsonSerializer::Serialize(RequestObj.ToSharedRef(),Writer);

        UE_LOG(LogTemp, Warning, TEXT("%s"), *RequestBody);

        ActiveRequest->SetContentAsString(RequestBody);
        ActiveRequest->OnProcessRequestComplete().BindUObject(this, &AOllama::OnResponseReceived);
        bool bStarted = ActiveRequest->ProcessRequest();

        UE_LOG(LogTemp, Warning, TEXT("Request Sent"));
        UE_LOG(LogTemp, Warning, TEXT("ProcessRequest=%s"), bStarted ? TEXT("true") : TEXT("false"));
        UE_LOG(LogTemp, Warning, TEXT("Request Point =%p"), ActiveRequest.Get());
        UE_LOG(LogTemp, Warning, TEXT("URL =%s"), *ActiveRequest->GetURL());
        return LastReply;
}

void AOllama::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    UE_LOG(LogTemp, Error, TEXT("CALLBACK FIRED"));
    UE_LOG(LogTemp, Warning, TEXT("OnResponseReceived Called"));
    UE_LOG(LogTemp, Warning, TEXT("Success=%s"), bWasSuccessful ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Warning, TEXT("Request URL =%s"), *Request ->GetURL());
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid()) {
        const TSharedPtr<FJsonObject>* MessageObj;
        if (JsonObject->TryGetObjectField(TEXT("message"), MessageObj)) {
                LastReply = (*MessageObj)->GetStringField(TEXT("content"));
                UE_LOG(LogTemp, Warning, TEXT("AI Reply = %s"), *LastReply);
            }
        }
    UE_LOG(LogTemp, Warning, TEXT("Response Code = %d"), Response->GetResponseCode());
    UE_LOG(LogTemp, Warning, TEXT("Response Body = %s"), *Response->GetContentAsString());
}

