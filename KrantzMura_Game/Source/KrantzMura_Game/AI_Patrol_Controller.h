// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Patrol_Controller.generated.h"

/**
 * 
 */
UCLASS()
class KRANTZMURA_GAME_API AAI_Patrol_Controller : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Patrol_Controller();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* Pawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;// gets the rotation of the patrol character

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawn);// this function processes any objects that are detected

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float PSightRadius = 600.0f; // aera where it can pick up the player

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float PatrolSightAge = 5.0f;// how long after it will chase when the player is out of sight

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float PatrolLoseSightRadius = PSightRadius + 50.0f;// the area which the ai loses site of the player and triggers the SightAge

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float FOV = 90.0f;// from each eye it has an angle of 90 degrees, and acts as periferal vision when both combined

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		class UAISenseConfig_Sight* SightConfig;// this lets us set up the sight settings
};
