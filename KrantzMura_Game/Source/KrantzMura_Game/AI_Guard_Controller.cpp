// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Guard_Controller.h"
#include "AI_Guard_Character.h"
#include "Waypoint.h"
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

	// checking to see if someone is friendly,Enemies or Neutrals
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());// sets the dominant sense to be vision
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Guard_Controller::OnPawnDetected);// updates the AI vision
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

void AAI_Guard_Controller::Tick(float DeltaSeconds)// runs every frame while the game is in play
{
	Super::Tick(DeltaSeconds);
	
	AAI_Guard_Character* Guard_Char = Cast<AAI_Guard_Character>(GetPawn());
	if (Guard_Char->NextWaypoint != nullptr) {
		MoveToActor(Guard_Char->NextWaypoint, 5.0f);//First param: moves to the next waypoint,Second param: how close it gets to it before it stops moving towards it
	}
}


void AAI_Guard_Controller::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
}


FRotator AAI_Guard_Controller::GetControlRotation() const
{
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AAI_Guard_Controller::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{

}

