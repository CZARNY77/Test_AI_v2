// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestManager.h"
#include "GameFramework/GameModeBase.h"
#include "Test_AI_v2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEST_AI_V2_API ATest_AI_v2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	ATest_AI_v2GameModeBase();
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Classes")
	TSubclassOf<UQuestManager> QuestManagerClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	class UQuestManager* QuestManagerInstance;

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
