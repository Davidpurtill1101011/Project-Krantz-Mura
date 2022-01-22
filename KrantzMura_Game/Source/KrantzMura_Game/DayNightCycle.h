// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DirectionalLight.h"
#include "Misc/OutputDeviceNull.h"
#include "GameFramework/Actor.h"
#include "DayNightCycle.generated.h"

UCLASS()
class KRANTZMURA_GAME_API ADayNightCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADayNightCycle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// slysphere property, can assign inside details panel, 
	UPROPERTY(EditAnywhere, Category = "Sky")
		AActor* sun; // is an AActor, the parent class of unreal skysphere is an AActor
	
	UPROPERTY(EditAnywhere, Category = "Sky")
		ADirectionalLight* lightsource; // class type of our light source

	UPROPERTY(EditAnywhere, Category = "Sky")	
		float turnRate; // turn rate of the two objects,

	// can be a variable within constructor, doesn't need to be UPROPERTY but makes
	// it easier to figure out when changing the scene as to what number we want 
};
