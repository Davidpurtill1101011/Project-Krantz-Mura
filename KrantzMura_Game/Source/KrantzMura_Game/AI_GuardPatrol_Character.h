// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_GuardPatrol_Character.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AAI_GuardPatrol_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_GuardPatrol_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint* Waypoint; // this starts out as null and needs to be set manually in Unreal Editor 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
