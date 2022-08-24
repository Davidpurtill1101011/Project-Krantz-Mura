// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include <Components/SkeletalMeshComponent.h>

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

	//SwordCollisionBox->AttachToComponent(RootComponent, AttachmentRules, "right_fist_col");
}

void AWeaponBase::Slash()
{
	SwordCollisionBox->SetCollisionProfileName("Weapon");
}

void AWeaponBase::StopSlash()
{
	SwordCollisionBox->SetCollisionProfileName("NoCollision");
}


