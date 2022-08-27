// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include <Components/SkeletalMeshComponent.h>
#include <KrantzMura_Game/Gillie.h>
#include <KrantzMura_Game/AI_GuardPatrol_Character.h>

// Sets default values
AWeaponBase::AWeaponBase()
{
 	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	RootComponent = WeaponMesh;

	SwordCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SwordCollisionBox"));
	SwordCollisionBox->SetupAttachment(RootComponent);
	SwordCollisionBox->SetCollisionProfileName("NoCollision");
	SwordCollisionBox->SetHiddenInGame(false);

	
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);

	
}

void AWeaponBase::Slash()
{
	SwordCollisionBox->SetCollisionProfileName("Weapon");
	TArray<AActor*> OverLappingActors;
	SwordCollisionBox->GetOverlappingActors(OverLappingActors);
	for (AActor* Actor : OverLappingActors) {
		if (Actor) {
			 if (AAI_GuardPatrol_Character* AiCharacter = Cast<AAI_GuardPatrol_Character>(Actor)) {
				AiCharacter->TakeDamage(10.0f, FDamageEvent(), nullptr, this);
			 }
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Attacked"));
}

void AWeaponBase::StopSlash()
{
	SwordCollisionBox->SetCollisionProfileName("NoCollision");
}




