// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Ollama.generated.h"

UCLASS()
class MYPROJECT_API AOllama : public AActor
{
    GENERATED_BODY()

public:
    AOllama();
    UFUNCTION(BlueprintCallable)
    FString GetAIResponse() const;
    UFUNCTION(BlueprintCallable)
    FString SendMessage(const FString& UserMessage);


protected:
    virtual void BeginPlay() override;



private:
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    FString LastReply;
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> ActiveRequest;
};