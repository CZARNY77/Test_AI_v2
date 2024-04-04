// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_AI_v2GameModeBase.h"

ATest_AI_v2GameModeBase::ATest_AI_v2GameModeBase()
{
	QuestManagerClass = UQuestManager::StaticClass();
}

void ATest_AI_v2GameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	if (QuestManagerClass != nullptr) {
		QuestManagerInstance = NewObject<UQuestManager>(this, QuestManagerClass);
	}
}
