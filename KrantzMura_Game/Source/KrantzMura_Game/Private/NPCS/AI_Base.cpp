// Fill out your copyright notice in the Description page of Project Settings.

#include <NPCS/GuardAIController.h>
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>

// Sets default values
AAI_Base::AAI_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;// lets the character to turn in the way it is walking
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);// turn rate of the AI

}

// Called when the game starts or when spawned
void AAI_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), WaypointsArray);
	MoveToWaypoints();
}

// Called every frame
void AAI_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Base::MoveToWaypoints()
{
	// this function lets the AI move to different waypoints set out in the area 
	// to patrol the set out spot.

	AGuardAIController* GuardAIController = Cast<AGuardAIController>(GetController());

	if (GuardAIController) {// checking to see if the cast was good
		if (CurrentWaypoint <= WaypointsArray.Num()) {
			for (AActor* Waypoints : WaypointsArray) 
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoints);
				if (WaypointItr) {
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint) {
						GuardAIController->MoveToActor(WaypointItr, 0.1f, false);
						CurrentWaypoint++;
						if (CurrentWaypoint > WaypointsArray.Num()) {
							CurrentWaypoint = 1;
							break;
						}
						break;
					}
					
				}
			}
		}
	}

}

