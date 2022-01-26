// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class KRANTZMURA_GAME_API AGuardAIController : public AAIController
{
	GENERATED_BODY()

public:
	AGuardAIController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* MyPawn) override;

	//virtual void OnUnPossess();

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);// this function lets the AI pickup on objects that have entered their vicinity
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float DetectSightRadius = 500.0f;// detection area

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float SightAge = 5.0f;// how long the AI keeps the object that is found in memory

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float LoseSightradius = DetectSightRadius + 25.0f;// the distance the Player needs to be away for the AI to lose sight of them

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float FieldOfView = 90.0f;// vision cone for the AI to spot the Player.

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		class UAISenseConfig_Sight* SightConfig;
};
