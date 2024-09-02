// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Fighter.h"
#include "FightingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATENTHUSIASTS_API UFightingGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<AFighter> LeftFighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<AFighter> RightFighter;
};
