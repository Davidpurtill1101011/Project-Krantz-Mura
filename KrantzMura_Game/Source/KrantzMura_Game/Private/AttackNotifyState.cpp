// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackNotifyState.h"
#include <KrantzMura_Game/Gillie.h>
#include<Engine.h>

void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) {
	UE_LOG(LogTemp, Warning, TEXT("BEGIN"));
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL) 
	{
		AGillie* Player = Cast<AGillie>(MeshComp->GetOwner());
		if (Player != NULL) {
			Player->StartAttack();
		}
	}

}

void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	UE_LOG(LogTemp, Warning, TEXT("END"));

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL) 
	{
		
		AGillie* Player = Cast<AGillie>(MeshComp->GetOwner());
		if (Player != NULL) {
			Player->StopAttack();
		}
	}

}