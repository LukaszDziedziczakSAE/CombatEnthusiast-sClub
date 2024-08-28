// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fighter.h"
#include "FightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COMBATENTHUSIASTS_API AFightGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AFighter* LeftFighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AFighter* RightFighter;
};
