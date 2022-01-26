// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCS/GuardAIController.h"
#include "NPCS/AI_Base.h"


void AGuardAIController::OnMoveCompleted(FAIRequestID ReqID, const FPathFollowingResult& Res)
{
	AAI_Base* AI_Base = Cast<AAI_Base>(GetPawn());// GetPawn will get a character type and treat it as the class defined

	if (AI_Base) {
		AI_Base->MoveToWaypoints();
	}
}
