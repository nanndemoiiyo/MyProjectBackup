// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Ollama.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnAIResponseReceived,
    FString,
    ResponseText);
struct ChildState {
    int Trust = 50;
    int SelfEsteem = 50;
    int Confidence = 50;
    int SocialSkill = 50;
    int Happiness = 50;
    int Stress = 0;
    void Clamp() {
        Trust = FMath::Clamp(Trust, 0, 100);
        SelfEsteem = FMath::Clamp(SelfEsteem, 0, 100);
        Confidence = FMath::Clamp(Confidence,0,100);
        SocialSkill = FMath::Clamp(SocialSkill,0,100);
        Happiness = FMath::Clamp(Happiness,0,100);
        Stress = FMath::Clamp(Stress,0,100);
    }
};

struct DayAction {
    FString Name;
    int TrustDelta = 0;
    int SelfEsteemDelta = 0;
    int ConfidenceDelta = 0;
    int SocialSkillDelta = 0;
    int HappinessDelta = 0;
    int StressDelta = 0;

    FString MemoryText;
    int MemoryImportance = 0;
};

struct Memory {
    FString Content;
    int Importance = 0;
    int DayCreated = 0;
};

UCLASS()
class MYPROJECT_API AOllama : public AActor
{
    GENERATED_BODY()

public:
    AOllama();
    UPROPERTY(BlueprintAssignable)
    FOnAIResponseReceived OnAIResponseReceived;
    UFUNCTION(BlueprintCallable)
    FString GetAIResponse() const;
    UFUNCTION(BlueprintCallable)
    FString SendMessage(const FString& UserMessage);
    UFUNCTION(BlueprintCallable)
    FString GetStatesText() const;
   

protected:
    virtual void BeginPlay() override;



private:
    int CurrentDay = 1;
    bool IsGameOver();
    bool bGameOver = false;
    bool bActionUsedToday = false;
    bool bTalkedToday = false;
    ChildState Child;
    FString LastReply;
    //îzóÒ
    TArray<TSharedPtr<FJsonValue>> ConversationHistory;
    TArray<DayAction> DailyActions;
    TArray<Memory> RecentMemories;
    TArray<Memory> LongTermMemories;
    TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> ActiveRequest;

    //string
    FString CreateRequestBody();
    FString BuildStateDescription() const;
    FString BuildSystemPrompt() const;
    FString BuildMemoryDescription() const;


    //voidä÷êî
    void ParseResponse(const FString& ResponseBody);
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    void CreateRequest();
    void SendRequest(const FString& RequestBody);
    void AddUserMessage(const FString& UserMessage);
    void AddAssistantMessage(const FString& AssistantMessage);
    void PrintConversationHistory();
    void AddSystemMessage();
    void ApplyAction(const DayAction& Action);
    void InitializeActions();
    void PrintActions() const;
    void PerformAction(int ActionIndex);
    void NextDay();
    void PrintDay() const;
    void AddMemory(const FString& Content, int Importance);
    void UpdateMemories();
    void PrintMemories() const;
    void EndDay();
    void ApplyEvaluation(const DayAction& Result);
    void ParseEvaluationResponse(const FString& ResponseBody);
    void EvaluateConversationWithAI(const FString& UserMessage);
};

