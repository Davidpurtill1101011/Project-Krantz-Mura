// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Perception/AISightTargetInterface.h>
#include <KrantzMura_Game/Public/WeaponBase.h>
#include <GenericTeamAgentInterface.h>
#include "AI_GuardPatrol_Character.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AAI_GuardPatrol_Character : public ACharacter, public IAISightTargetInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_GuardPatrol_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint* Waypoint; // this starts out as null and needs to be set manually in Unreal Editor 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		int32 ID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI") 
		bool Attack = false;
		

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
		class UAnimMontage* SwordMontage; // this lets bind to the blueprint via C++ code

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWeaponBase> WeaponClass;

	class AWeaponBase* Weapon;

	void AttackPlayer();

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FGenericTeamId TeamId;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
