// Fill out your copyright notice in the Description page of Project Settings.


#include "Patrol_Points.h"

// Sets default values
APatrol_Points::APatrol_Points()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatrol_Points::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrol_Points::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

