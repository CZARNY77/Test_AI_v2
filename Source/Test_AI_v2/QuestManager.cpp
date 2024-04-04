// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values for this component's properties
UQuestManager::UQuestManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQuestManager::AddQuest(UQuestBase* Quest)
{
	if (Quest != nullptr) {
		ActiveQuests.Add(Quest);
	}
}

void UQuestManager::ActivateQuest(FName QuestID)
{
}

void UQuestManager::IsQuestCompleted(FName QuestID) const
{
}

TArray<UQuestBase*> UQuestManager::GetActiveQuests() const
{
	return TArray<UQuestBase*>();
}

TArray<UQuestBase*> UQuestManager::GetCompletedQuests() const
{
	return TArray<UQuestBase*>();
}

