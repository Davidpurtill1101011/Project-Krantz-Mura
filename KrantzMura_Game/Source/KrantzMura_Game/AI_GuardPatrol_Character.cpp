// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_GuardPatrol_Character.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <KrantzMura_Game/Gillie.h>
// Sets default values
AAI_GuardPatrol_Character::AAI_GuardPatrol_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIHealth = DefaultHealth;

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
	Weapon->SwordCollisionBox->SetCollisionProfileName("Weapon");
	TArray<AActor*> OverLappingActors;
	Weapon->SwordCollisionBox->GetOverlappingActors(OverLappingActors);
	for (AActor* Actor : OverLappingActors) {
		if (Actor) {
			if (AGillie* Character = Cast<AGillie>(Actor)) {
				Character->TakeDamage(10.0f, FDamageEvent(), nullptr, this);
			}
			
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Attacked"));
	
	
}

void AAI_GuardPatrol_Character::DontAttackPlayer()
{
	Weapon->StopSlash();
}



float AAI_GuardPatrol_Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	AIHealth -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), AIHealth);

	if (AIHealth <= 0)
	{
		//Destroy();
		UE_LOG(LogTemp, Warning, TEXT("AIHealth Depleted: %f"), AIHealth);
	}
	return DamageAmount;
}

