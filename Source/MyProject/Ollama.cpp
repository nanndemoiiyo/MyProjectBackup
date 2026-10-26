// Fill out your copyright notice in the Description page of Project Settings.

#include "Ollama.h"
#include "HttpModule.h"
#include "Json.h"
#include "JsonUtilities.h"


//=============================================
//Constructor
//=============================================
AOllama::AOllama()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AOllama::BeginPlay()
{
    Super::BeginPlay();
    InitializeActions();
    PrintActions();
    ApplyAction(DailyActions[0]);
    UE_LOG(LogTemp,Warning,TEXT("%s"),*BuildStateDescription());
    LastReply = TEXT("hello");
}
//========================
//AI通信関係
//========================

//返信確保
FString AOllama::GetAIResponse() const
{
    UE_LOG(LogTemp, Warning, TEXT("GetAIResponse = %s"), * LastReply);
    return LastReply;
}

//メッセージ送信
FString AOllama::SendMessage( const FString& UserMessage)
{
    LastReply = TEXT("Sending...");
    AddUserMessage(UserMessage);
    CreateRequest();
    FString RequestBody = CreateRequestBody();
    SendRequest(RequestBody);
    bTalkedToday = true;
    return LastReply;
}


FString AOllama::CreateRequestBody() {

    TSharedPtr<FJsonObject> RequestObj = MakeShareable(new FJsonObject);
    RequestObj->SetStringField(TEXT("model"), TEXT("phi3:mini"));
    RequestObj->SetBoolField(TEXT("stream"), false);

    TArray<TSharedPtr<FJsonValue>> Messages;

    //System Message
    TSharedPtr<FJsonObject> SystemObj = MakeShareable(new FJsonObject);
    SystemObj->SetStringField(TEXT("role"), TEXT("system"));
    SystemObj->SetStringField(TEXT("content"), BuildSystemPrompt());
    Messages.Add(MakeShareable(new FJsonValueObject(SystemObj)));

    //ConversationHistory
    for (const TSharedPtr<FJsonValue>& Msg : ConversationHistory) {
        Messages.Add(Msg);
    }
    RequestObj->SetArrayField(TEXT("messages"), Messages);

    FString RequestBody;

    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(RequestObj.ToSharedRef(), Writer);
    return RequestBody;
}


//CreateJson
void AOllama::CreateRequest() {
    ActiveRequest = FHttpModule::Get().CreateRequest();
    ActiveRequest->SetURL(TEXT("http://127.0.0.1:11434/api/chat"));
    ActiveRequest->SetVerb(TEXT("POST"));
    ActiveRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
}

//JsonをHTTPリクエストに入れる
void AOllama::SendRequest(const FString& RequestBody) {
    ActiveRequest->SetContentAsString(RequestBody);
    ActiveRequest->SetTimeout(60.0f);
    ActiveRequest->OnProcessRequestComplete().BindUObject(this, &AOllama::OnResponseReceived);
    bool bStarted = ActiveRequest->ProcessRequest();
    UE_LOG(LogTemp, Warning, TEXT("ProcessRequest=%s"), bStarted ? TEXT("true") : TEXT("false"));
}


void AOllama::ParseResponse(const FString& ResponseBody) {
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid()) {
        const TSharedPtr<FJsonObject>* MessageObj = nullptr;
        if (JsonObject->TryGetObjectField(TEXT("message"), MessageObj) && MessageObj && (*MessageObj).IsValid()) {
            LastReply = (*MessageObj)->GetStringField(TEXT("content"));
            AddAssistantMessage(LastReply);
            OnAIResponseReceived.Broadcast(LastReply);
            UE_LOG(LogTemp, Warning, TEXT("AI Reply = %s"), *LastReply);
        }
    }
}

//AI返信がきたかの確認
void AOllama::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    if (!Request.IsValid()) {
        UE_LOG(LogTemp, Error, TEXT("Request Invalid"));
        return;
    }
    if (!Response.IsValid()) {
        UE_LOG(LogTemp, Error, TEXT("Response Invalid"));
        return;
    }
    if (!bWasSuccessful) {
        UE_LOG(LogTemp, Error, TEXT("Request Failed"));
        return;
    }
    ParseResponse(Response->GetContentAsString());
}
//===================
//会話履歴
//===================

void AOllama::AddUserMessage(const FString& UserMessage) {
    TSharedPtr<FJsonObject> MessageObj = MakeShareable(new FJsonObject);
    MessageObj->SetStringField(TEXT("role"), TEXT("user"));
    MessageObj->SetStringField(TEXT("content"), UserMessage);
    ConversationHistory.Add(MakeShareable(new FJsonValueObject(MessageObj)));
    PrintConversationHistory();
}

void AOllama::AddSystemMessage() {
    TSharedPtr<FJsonObject> MessageObj = MakeShareable(new FJsonObject);
    MessageObj->SetStringField(TEXT("role"), TEXT("system"));
    MessageObj->SetStringField(TEXT("content"), BuildSystemPrompt());
    ConversationHistory.Add(MakeShareable(new FJsonValueObject(MessageObj)));
}

//履歴保存
void AOllama::AddAssistantMessage(const FString& AssistantMessage) {
    TSharedPtr<FJsonObject> MessageObj = MakeShareable(new FJsonObject);
    MessageObj->SetStringField(TEXT("role"), TEXT("assistant"));
    MessageObj->SetStringField(TEXT("content"), AssistantMessage);
    ConversationHistory.Add(MakeShareable(new FJsonValueObject(MessageObj)));
}

void AOllama::PrintConversationHistory() {
    UE_LOG(LogTemp, Warning, TEXT("History Count = %d"), ConversationHistory.Num());
    for (int i = 0; i < ConversationHistory.Num(); i++) {
        TSharedPtr<FJsonObject> MessageObj = ConversationHistory[i]->AsObject();
        FString  MessageRole = MessageObj->GetStringField(TEXT("role"));
        FString Content = MessageObj->GetStringField(TEXT("content"));
        UE_LOG(LogTemp, Warning, TEXT("[%s] %s"), *MessageRole, *Content);
    }
}

//=========================
//System
//=======================


//GameSystem
FString AOllama::BuildStateDescription() const {
    FString StateText;
    StateText += FString::Printf(TEXT("Trust=%d\n"),Child.Trust);
    StateText += FString::Printf(TEXT("SelfEsteem=%d\n"),Child.SelfEsteem);
    StateText += FString::Printf(TEXT("Confidence=%d\n"), Child.Confidence);
    StateText += FString::Printf(TEXT("SocialSkill=%d\n"), Child.SocialSkill);
    StateText += FString::Printf(TEXT("Happinessl=%d\n"), Child.Happiness);
    StateText += FString::Printf(TEXT("Stress=%d\n"), Child.Stress);
    return StateText;
}
//AI設定
FString AOllama::BuildSystemPrompt() const
{
    FString Prompt;
    Prompt += TEXT(
        "You are a 5-year-old child.\n");

    Prompt += TEXT(
        "Current State:\n");

    Prompt += BuildStateDescription();

    Prompt += BuildMemoryDescription();

    Prompt += TEXT(
        "\nYour memories affect how you feel about your parent.\n"
        "Positive memories make you more trusting and open.\n"
        "Negative memories make you more cautious or distant.\n"
        "Recent memories are vivid.\n"
        "Important memories strongly influence your personality.\n");

    Prompt += TEXT(
        "\nRespond like a child.");

    return Prompt;
}

FString AOllama::BuildMemoryDescription() const {
    FString MemoryText;
    MemoryText += TEXT("\nRecent Memories:\n");
    for (const Memory& Mem : RecentMemories) {
        MemoryText += TEXT("-") + Mem.Content + TEXT("\n");
    }
    MemoryText += TEXT("\nImportant Memories:\n");
    for (const Memory& Mem : LongTermMemories) {
        MemoryText += TEXT("-") + Mem.Content + TEXT("\n");
    }
    return MemoryText;
}

//=======================
//Child State
//========================

//GemOver判定
bool AOllama::IsGameOver() {
    if (Child.Trust <= 0 ) {
        UE_LOG(LogTemp, Warning, TEXT("Run Away Ending"));

        bGameOver = true;
    }
    if (Child.SelfEsteem <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Self Esteem Ending"));

bGameOver = true;
    }
    if (Child.Happiness <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Depresssion Ending"));

        bGameOver = true;
    }
    if (Child.Stress >= 100) {
        UE_LOG(LogTemp, Warning, TEXT("Stress Ending"));

        bGameOver = true;
    }
    if (CurrentDay >= 100) {
        UE_LOG(LogTemp, Warning, TEXT("Normal Ending"));

        bGameOver = true;
    }
    return bGameOver;
}

void AOllama::PrintState() const {
    UE_LOG(LogTemp, Warning, TEXT("Trust: %d"), Child.Trust);
    UE_LOG(LogTemp, Warning, TEXT("SelfEsteem: %d"), Child.SelfEsteem);
    UE_LOG(LogTemp, Warning, TEXT("Confidence: %d"), Child.Confidence);
    UE_LOG(LogTemp, Warning, TEXT("SocialSkill: %d"), Child.SocialSkill);
    UE_LOG(LogTemp, Warning, TEXT("Happiness: %d"), Child.Happiness);
    UE_LOG(LogTemp, Warning, TEXT("Stress: %d"), Child.Stress);
}

//======================
//Day System
//=======================
void AOllama::NextDay() {
    CurrentDay++;
    UpdateMemories();
    UE_LOG(LogTemp, Warning, TEXT("Day %d"), CurrentDay);
}

void AOllama::PrintDay() const {
    UE_LOG(LogTemp, Warning, TEXT("Day %d"), CurrentDay);
}

void AOllama::EndDay() {
    if (!bActionUsedToday) {
        UE_LOG(LogTemp,Warning,TEXT("You have not chosen an action today"));
        return;
    }
    if (!bTalkedToday) {
        UE_LOG(LogTemp,Warning,TEXT("You have not talked today"));
        return;
    }
    NextDay();
    bActionUsedToday = false;
    bTalkedToday = false;
    if (IsGameOver()) {
        UE_LOG(LogTemp, Warning, TEXT("Game Over"));
    }
}
//====================
//Action System
//=====================
void AOllama::ApplyAction(const DayAction& Action) {
    Child.Trust += Action.TrustDelta;
    Child.SelfEsteem += Action.SelfEsteemDelta;
    Child.Confidence += Action.ConfidenceDelta;
    Child.SocialSkill += Action.SocialSkillDelta;
    Child.Happiness += Action.HappinessDelta;
    Child.Stress += Action.StressDelta;
    Child.Clamp();
}

//行動選択
void AOllama::InitializeActions() {
    DayAction Study;
    Study.Name = TEXT("一緒に勉強する");
    Study.ConfidenceDelta = 5;
    Study.StressDelta = 2;
    Study.TrustDelta = 1;
    Study.MemoryImportance = 3;
    Study.MemoryText = TEXT("親と一緒に勉強した");

    DailyActions.Add(Study);

    DayAction Play;
    Play.Name = TEXT("一緒に公園で遊ぶ");
    Play.SocialSkillDelta = 5;
    Play.HappinessDelta = 3;
    Play.StressDelta = -2;
    Play.MemoryImportance = 4;
    Play.MemoryText = TEXT("親と公園で遊んだ");

    DailyActions.Add(Play);

    DayAction Scold;
    Scold.Name = TEXT("強くしかる");
    Scold.TrustDelta = -5;
    Scold.SelfEsteemDelta = -3;
    Scold.StressDelta = 6;
    Scold.MemoryImportance = 8;
    Scold.MemoryText = TEXT("親に強くしかられた");

    DailyActions.Add(Scold);
}

void AOllama::PerformAction(int ActionIndex) {
    if (!DailyActions.IsValidIndex(ActionIndex)) {
        UE_LOG(LogTemp, Error, TEXT("Invalid Action Index"));
        return;
    }
    if (bActionUsedToday){
        UE_LOG(LogTemp, Warning, TEXT("Action already used today"));
        return;
    }
    ApplyAction(DailyActions[ActionIndex]);
    AddMemory(DailyActions[ActionIndex].MemoryText, DailyActions[ActionIndex].MemoryImportance);
    UE_LOG(LogTemp, Warning, TEXT("Actions: %s"), *DailyActions[ActionIndex].Name);
    PrintState();
    PrintMemories();
   
}

void AOllama::PrintActions() const {
    UE_LOG(LogTemp,Warning,TEXT("Actions"));
    for (int i = 0; i < DailyActions.Num(); i++) {
        UE_LOG(LogTemp, Warning, TEXT("%d :%s"), i + 1, *DailyActions[i].Name);
    }
}


//=========================
//Memory System
//===========================

//記憶処理
void AOllama::AddMemory(const FString& Content, int Importance) {
    Memory NewMemory;

    NewMemory.Content = Content;
    NewMemory.Importance = Importance;
    NewMemory.DayCreated = CurrentDay;
    if (Importance >= 7) {
        LongTermMemories.Add(NewMemory);
    }
    else {
        RecentMemories.Add(NewMemory);
    }

}

void AOllama::UpdateMemories() {
    for (int i = RecentMemories.Num() - 1; i >= 0; i--) {
        int MemoryAge = CurrentDay - RecentMemories[i].DayCreated;
        if (MemoryAge >= 7) {
            RecentMemories.RemoveAt(i);
        }
    }
}

void AOllama::PrintMemories() const {
    UE_LOG(LogTemp,Warning,TEXT("Recent Memories"));
    for (const Memory& Mem : RecentMemories) {
        UE_LOG(LogTemp, Warning, TEXT("%s | Importance:%d | Day:%d"),*Mem.Content,Mem.Importance,Mem.DayCreated);
    }
    for (const Memory& Mem : LongTermMemories) {
        UE_LOG(LogTemp,Warning,TEXT("%s | Importance:%d | Day:%d"),*Mem.Content,Mem.Importance,Mem.DayCreated);

    }
}
