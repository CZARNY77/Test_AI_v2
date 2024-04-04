// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class TEST_AI_V2_API UQuestBase : public UObject
{
	GENERATED_BODY()
	
public:
	UQuestBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	int EXPReward;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	//TArray<AActor> ItemsReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest")
	bool bIsCompleted;

	UFUNCTION(BlueprintCallable, Category = "Quest")
	virtual void ActivateQuest();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	virtual void CompleteQuest();
};
