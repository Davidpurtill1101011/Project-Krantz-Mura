// Fill out your copyright notice in the Description page of Project Settings.
// this is the representation of the NPC in the world
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_Guard_Character.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AAI_Guard_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Guard_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
