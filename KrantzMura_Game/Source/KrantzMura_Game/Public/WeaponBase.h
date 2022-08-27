// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "WeaponBase.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
		class UAnimationAsset* SlashAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Collision")
		class UBoxComponent* SwordCollisionBox;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void Slash();
	void StopSlash();

	
};
