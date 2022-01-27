// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Guard_Controller.h"
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>


AAI_Guard_Controller::AAI_Guard_Controller() {
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	// setting the variables for the perception
	SightConfig->SightRadius = AIVisionRadius;
	SightConfig->LoseSightRadius = LoseVisionRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFov;
	SightConfig->SetMaxAge(VisionAge);

	// checking to see if someone is friendly or now
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());// sets the dominant sense to be vision
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Guard_Controller::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}


void AAI_Guard_Controller::BeginPlay()
{
	Super::BeginPlay();
	if (GetPerceptionComponent() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Trouble Logging info"));
	}
	
}

void AAI_Guard_Controller::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
}

void AAI_Guard_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator AAI_Guard_Controller::GetControlRotation() const
{
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AAI_Guard_Controller::OnPawnDetected(const TArray<AActor*> &DetectedPawns)
{

}

