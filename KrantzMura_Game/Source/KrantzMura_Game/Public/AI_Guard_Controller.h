// Fill out your copyright notice in the Description page of Project Settings.
// this class is used to setup the movements of the NPC/AI throughout the world
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Guard_Controller.generated.h"

/**
 * 
 */
UCLASS()
class KRANTZMURA_GAME_API AAI_Guard_Controller : public AAIController
{
	GENERATED_BODY()

public:
	AAI_Guard_Controller();// constructor method

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* Pawn) override;// runs when it plugs into the character

	virtual void Tick(float DeltaSeconds) override;// ran every frame

	virtual FRotator GetControlRotation() const override;// makes the character to face that it is pointing 

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);//processes any detected components/Objects(Player,friendly,neutral)

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIVisionRadius = 500.0f;// when the player will be spotted

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float VisionAge = 5.0f;// how long after the the player has left the vision it forgets

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float LoseVisionRadius = AIVisionRadius + 50.0f;// when it cant see the player anymore

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIFov = 90.0f;// field of view

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		class UAISenseConfig_Sight* SightConfig;

	
};
