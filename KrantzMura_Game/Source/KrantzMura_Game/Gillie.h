// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Components/BoxComponent.h>
#include <Components/InputComponent.h>
#include <Sound/SoundCue.h>
#include <Components/AudioComponent.h>
#include <GameFramework/Controller.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "Components/CapsuleComponent.h"
#include "Door.h"
#include <GenericTeamAgentInterface.h>
#include <KrantzMura_Game/Structs.h>
#include "Gillie.generated.h"


class AItem;

UCLASS()
class KRANTZMURA_GAME_API AGillie : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGillie();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Camera")// making the camera boom
		USpringArmComponent* CameraBoom; // * means that it is a type of SpringArm and the U means it will be picked up by GB collection..

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Camera")// camera Follows the player
		UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Character Movement: Walking")
		float SprintSpeedMultiplier;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Character Movement: Walking")
		float WalkSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
		class UAnimMontage* FightingMontage; // this lets bid to the blueprint via C++ code

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Collision)
		class UBoxComponent* LeftFistCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Collision)
		class UBoxComponent* RightFistCollision;


	UPROPERTY(BlueprintReadWrite, Category= "Health")
		float Health;

	UPROPERTY(BlueprintReadWrite, Category = "Health")
		float Hunger;

	// sound cue
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Audio);
	class USoundCue* PunchSoundCue;

	//FUNCTIONS
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
		void AddItemToInventoryWidget(FItem_Information ItemData, const TArray<FItem_Information>& CurrentInvent = TArray<FItem_Information>());

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
		void UpdateInventoryWidget(const TArray<FItem_Information>& NewInventoryItems);

	UFUNCTION(BlueprintCallable, Category = "Inventory System")
		void ItemUse(TSubclassOf<AItem> ItemSubClass);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory System")
		void UpdatePlayerStats(float NewHunger, float NewHealth);

	UPROPERTY(BlueprintReadWrite, Category = "Inventory System")
		TArray<FItem_Information> InventoryItems;

	UFUNCTION()
		void Inventory_Items();

	void AddHealth(float Value);
	void RemoveHunger(float Value);

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartCrouching();

	void Sprint();
	void StopSprinting();

	void Walking();
	void StopWalking();

	void DoorInteract();
	void ItemInteract();

	// functions for fighting
	void StartAttack();
	void StopAttack();
	void AttackInput();
	UFUNCTION()
		void AttackHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// for the inventory system
	void AddInventoryItem(FItem_Information Item_Info);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FGenericTeamId TeamId;

	UAudioComponent* PunchAudioComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

};
