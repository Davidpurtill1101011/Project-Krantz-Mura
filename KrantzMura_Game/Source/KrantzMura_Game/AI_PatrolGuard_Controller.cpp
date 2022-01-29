// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_PatrolGuard_Controller.h"
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>

AAI_PatrolGuard_Controller::AAI_PatrolGuard_Controller() // constructor
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AIVisionRadius;
	SightConfig->LoseSightRadius = AILossOfSight;
	SightConfig->PeripheralVisionAngleDegrees = FOV;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation()); //setting sight to be the most dominant sense for the ai to find the player
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_PatrolGuard_Controller::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void AAI_PatrolGuard_Controller::BeginPlay()
{
	Super::BeginPlay();
	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Some Problem Occured"));
	}
}

void AAI_PatrolGuard_Controller::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
}

void AAI_PatrolGuard_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator AAI_PatrolGuard_Controller::GetControlRotation() const
{
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
	
}

void AAI_PatrolGuard_Controller::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
}
