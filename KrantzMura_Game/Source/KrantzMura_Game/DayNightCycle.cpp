// Fill out your copyright notice in the Description page of Project Settings.


#include "DayNightCycle.h"

// Sets default values
ADayNightCycle::ADayNightCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADayNightCycle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADayNightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// rotate our two objects from here
	if (lightsource)
	{
		// roll about the x-axis
		lightsource->AddActorLocalRotation(FRotator(-(DeltaTime * turnRate), 0, 0));
	}

	if (sun)
	{
		// call function inside our skySphere function
		FOutputDeviceNull ar;
		// ar=output, NULL=no executor, true=force executor when none as we don't have an executor
		sun->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);
	}
}

