// Fill out your copyright notice in the Description page of Project Settings.

#include <NPCS/GuardAIController.h>
#include <NPCS/Waypoint.h>
#include "NPCS/AI_Base.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AAI_Base::AAI_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
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
		if (CurrentWaypoint <= Waypoints.Num()) {
			for (AActor* Waypoint_s : Waypoints) 
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint_s);
				if (WaypointItr) {
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint) {
						GuardAIController->MoveToActor(WaypointItr, 10.0f, false);
						CurrentWaypoint++;
						break;
					}
				}
			}
		}
	}

}

