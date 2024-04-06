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

void UQuestManager::AddQuest()
{
	UFetchQuest* NewQuest = NewObject<UFetchQuest>(this, FetchQuestClass);

	ActiveQuests.Add(NewQuest);

}

void UQuestManager::ActivateQuest(FName QuestID)
{
	for (UQuestBase* Quest : ActiveQuests) {
		if (Quest && Quest->ID == QuestID) {
			Quest->ActivateQuest();
			break;
		}
	}
}

void UQuestManager::CompletedQuest(FName QuestID)
{
	for (UQuestBase* Quest : ActiveQuests) {
		if (Quest && Quest->ID == QuestID && !Quest->bIsCompleted) {
			Quest->CompleteQuest();
			CompletedQuests.Add(Quest);
			ActiveQuests.Remove(Quest);
			break;
		}
	}
}

bool UQuestManager::IsQuestCompleted(FName QuestID) const
{
	for (UQuestBase* Quest : CompletedQuests) {
		if (Quest && Quest->ID == QuestID) {
			return true;
		}
	}
	return false;
}

TArray<UQuestBase*> UQuestManager::GetActiveQuests() const
{
	//return TArray<UQuestBase*>();
	return ActiveQuests;
}

TArray<UQuestBase*> UQuestManager::GetCompletedQuests() const
{
	//return TArray<UQuestBase*>();
	return CompletedQuests;
}

UFetchQuest* UQuestManager::ConstructFetchQuest(FName QuestID, FText QuestName, FText Description, int ExpReward, FName ItemID, int32 RequiredItemCount)
{
	UFetchQuest* NewQuest = NewObject<UFetchQuest>(this);
	if (NewQuest != nullptr)
	{
		// Inicjalizacja w�a�ciwo�ci nowego questu
		NewQuest->ID = QuestID;
		NewQuest->Name = QuestName;
		NewQuest->Description = Description;
		NewQuest->EXPReward = ExpReward;
		NewQuest->bIsCompleted = false;
		NewQuest->ItemID = ItemID;
		NewQuest->RequiredItemCount = RequiredItemCount;
		//NewQuest->ActivateQuest();

		ActiveQuests.Add(NewQuest);
	}
	return NewQuest;
}
