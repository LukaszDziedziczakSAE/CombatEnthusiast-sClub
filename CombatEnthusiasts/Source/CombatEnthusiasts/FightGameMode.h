// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fighter.h"
#include "Spawner.h"
#include "FightingGameInstance.h"
#include "FighterController.h"
#include "FightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COMBATENTHUSIASTS_API AFightGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bDoNotSpawnSecondControler;

public:
	AFightGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RoundTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Timer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int MaxRounds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Round;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int LeftWins;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int RightWins;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFighter> DefaultFighter;
	
public:
	virtual void Tick(float DeltaTime) override;


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
	void SpawnFighters();

	UFUNCTION(BlueprintCallable)
	void DespawnFighters();

	UFUNCTION(BlueprintCallable)
	void StartNewRound();

	UFUNCTION(BlueprintImplementableEvent)
	void ReturnToMenu();

	UFUNCTION(BlueprintCallable)
	void AddLeftWin();

	UFUNCTION(BlueprintCallable)
	void AddRightWin();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AFighterController* Player1Controller;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AFighterController* Player2Controller;
};
