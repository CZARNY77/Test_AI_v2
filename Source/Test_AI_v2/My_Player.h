// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "My_Player.generated.h"

UCLASS()
class TEST_AI_V2_API AMy_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMy_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
