// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Perception/AIPerceptionComponent.h>
#include "AI_PatrolGuard_Controller.generated.h"

/**
 * 
 */
UCLASS()
class KRANTZMURA_GAME_API AAI_PatrolGuard_Controller : public AAIController
{
	GENERATED_BODY()

public: 
	AAI_PatrolGuard_Controller(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* Pawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*>& DetectedPawns);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIVisionRadius = 1000.0f; // Area where the AI can detect the player when seen

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AISightAge = 5.0f; // how long the ai keeps looking for the player after the player has left the radius

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AILossOfSight = AIVisionRadius + 100.0f; //this is the radius for when the AI looses sight of the player

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float FOV = 90.0f; // FOV sets both eyes to be 90 degree angles and then they both work like periferal vision (180 degrees of vision)

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		bool isPlayerDetected;// checks to see if the the player is in the detectionzone

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float PlayerDistance;// checking to see how far away the player is

	UPROPERTY(BlueprintReadWrite)
		class AAI_GuardPatrol_Character* Guard;

	class AWeaponBase* Weapon;

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	
protected:
	UPROPERTY(VisibleAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;

	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

};
