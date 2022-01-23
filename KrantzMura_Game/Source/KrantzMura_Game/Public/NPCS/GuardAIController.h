// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class KRANTZMURA_GAME_API AGuardAIController : public AAIController
{
	GENERATED_BODY()

	// this function lets the ai do the loop of the patrol again
	virtual void OnMoveCompleted(FAIRequestID ReqID, const FPathFollowingResult& Res) override;
};
