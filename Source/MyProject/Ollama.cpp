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
        ActiveRequest->SetURL(TEXT("http;//127.0.0.1:11434/api/chat"));
        ActiveRequest->SetVerb(TEXT("POST"));
        ActiveRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
        UE_LOG(LogTemp, Warning, TEXT("Request Created"));
        return LastReply;
}