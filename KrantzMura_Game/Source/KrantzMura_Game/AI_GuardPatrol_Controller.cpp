// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_GuardPatrol_Controller.h"

// Sets default values
AAI_GuardPatrol_Controller::AAI_GuardPatrol_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_GuardPatrol_Controller::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_GuardPatrol_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

