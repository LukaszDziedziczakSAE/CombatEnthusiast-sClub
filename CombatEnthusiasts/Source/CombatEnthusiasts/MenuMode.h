// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fighter.h"
#include "Spawner.h"
#include "FightingGameInstance.h"
#include "MenuMode.generated.h"

/**
 * 
 */
UCLASS()
class COMBATENTHUSIASTS_API AMenuMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFighter> DefaultFighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AFighter* LeftFighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AFighter* RightFighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ASpawner* LeftSpawner;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ASpawner* RightSpawner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFightingGameInstance* FightingGameInstance;

	UFUNCTION(BlueprintCallable)
	void SelectLeftFighter(TSubclassOf<AFighter> Fighter);
	
	UFUNCTION(BlueprintCallable)
	void SelectRightFighter(TSubclassOf<AFighter> Fighter);
};
