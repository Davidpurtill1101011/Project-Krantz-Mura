// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCS/AI_Base.h"
#include "NPCS/GuardAIController.h"
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "NPCS/AI_Base.h"


=======

>>>>>>> parent of 6a70b29 (Added some code for the Ai to do its own thing #10)
=======

>>>>>>> parent of 6a70b29 (Added some code for the Ai to do its own thing #10)
=======

>>>>>>> parent of 6a70b29 (Added some code for the Ai to do its own thing #10)
void AGuardAIController::OnMoveCompleted(FAIRequestID ReqID, const FPathFollowingResult& Res)
{
	AAI_Base* AI_Base = Cast<AAI_Base>(GetPawn());// GetPawn will get a character type and treat it as the class defined

	if (AI_Base) {
		AI_Base->MoveToWaypoints();
	}
}
