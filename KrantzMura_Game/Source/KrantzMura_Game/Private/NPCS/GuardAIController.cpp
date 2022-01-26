// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCS/GuardAIController.h"
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>

AGuardAIController::AGuardAIController(){
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = DetectSightRadius;
	SightConfig->LoseSightRadius = LoseSightradius;
	SightConfig->PeripheralVisionAngleDegrees = FieldOfView;
	SightConfig->SetMaxAge(SightAge);

	// setting all the AI detections to true(This is the vision/eye-sight of the AI)
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	
	//Perception object set to know what to do when the game is running.
	// setting sight to be the most domiant sense the AI will use to spot the player
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AGuardAIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}
void AGuardAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AGuardAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
}

void AGuardAIController::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
}



FRotator AGuardAIController::GetControlRotation() const
{
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
	
}

void AGuardAIController::OnPawnDetected(const TArray<AActor*> &DetectedPawns)
{

}
