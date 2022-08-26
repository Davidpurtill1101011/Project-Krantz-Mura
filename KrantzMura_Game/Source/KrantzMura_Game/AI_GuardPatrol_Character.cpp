// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_GuardPatrol_Character.h"
#include <GameFramework/CharacterMovementComponent.h>
// Sets default values
AAI_GuardPatrol_Character::AAI_GuardPatrol_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;// these two methods work together to move/turn the ai in the direction it is moving
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);// the speed it turns at
	
	//weapon setup
	static ConstructorHelpers::FObjectFinder<UAnimMontage>SwordMontageObj(TEXT("AnimMontage'/Game/Mannequin/Animations/Fighting/AI_SwordAnin.AI_SwordAnin'"));
	if (SwordMontageObj.Succeeded()) {
		SwordMontage = SwordMontageObj.Object;
	}

}


// Called when the game starts or when spawned
void AAI_GuardPatrol_Character::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters SpawnParams;
	if (WeaponClass) {
		SpawnParams.bNoFail = true;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		FTransform WeaponTransform;
		WeaponTransform.SetLocation(FVector::ZeroVector);
		WeaponTransform.SetRotation(FQuat(FRotator::ZeroRotator));
		Weapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponClass, WeaponTransform, SpawnParams);
		if (Weapon) {
			Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("right_fist_col"));
		}
	}
	
}

// Called every frame
void AAI_GuardPatrol_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_GuardPatrol_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AAI_GuardPatrol_Character::AttackPlayer()
{
	
	//FString SwordSwingMontage = "Start_";
	PlayAnimMontage(SwordMontage, .5f, FName("Start_1"));
	
}

