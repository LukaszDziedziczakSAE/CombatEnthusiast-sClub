// Fill out your copyright notice in the Description page of Project Settings.


#include "FightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"

AFightGameMode::AFightGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFightGameMode::BeginPlay()
{
	Super::BeginPlay();

	FightingGameInstance = Cast<UFightingGameInstance>(GetGameInstance());

	TArray<AActor*> Spawners;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawner::StaticClass(), Spawners);
	for (AActor* SpawnerActor : Spawners)
	{
		ASpawner* Spawner = Cast<ASpawner>(SpawnerActor);
		if (Spawner != nullptr)
		{
			if (Spawner->GetSide() == EFighterSide::Left) LeftSpawner = Spawner;
			if (Spawner->GetSide() == EFighterSide::Right) RightSpawner = Spawner;
		}
	}

	if (LeftSpawner == nullptr) UE_LOG(LogTemp, Error, TEXT("Missing Left Spawner Referance"));
	if (RightSpawner == nullptr) UE_LOG(LogTemp, Error, TEXT("Missing Right Spawner Referance"));
	if (FightingGameInstance == nullptr) UE_LOG(LogTemp, Error, TEXT("Missing FightingGameInstance Referance"));

	Player1Controller = Cast<AFighterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (Player1Controller == nullptr) UE_LOG(LogTemp, Error, TEXT("Missing Player1Controller Referance"));

	if (!bDoNotSpawnSecondControler)
	{
		FString LocalPlayerError = TEXT("Error creating new Local Player");
		GetGameInstance()->CreateLocalPlayer(1, LocalPlayerError, true);
		Player2Controller = Cast<AFighterController>(UGameplayStatics::GetPlayerController(GetWorld(), 1));
		if (Player2Controller == nullptr) UE_LOG(LogTemp, Error, TEXT("Missing Player2Controller Referance"));
	}

	if (DefaultFighter != nullptr)
	{
		if (FightingGameInstance->LeftFighter == nullptr) FightingGameInstance->LeftFighter = DefaultFighter;
		if (FightingGameInstance->RightFighter == nullptr) FightingGameInstance->RightFighter = DefaultFighter;
	}

	
	UE_LOG(LogTemp, Display, TEXT("Begining Fight"));
	StartNewRound();
}

void AFightGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timer > 0) Timer -= DeltaTime;
	else
	{
		if (LeftFighter->Health->GetCurretHealth() > RightFighter->Health->GetCurretHealth())
		{
			AddLeftWin();
		}

		else if (LeftFighter->Health->GetCurretHealth() < RightFighter->Health->GetCurretHealth())
		{
			AddRightWin();
		}

		StartNewRound();
	}
}

void AFightGameMode::SpawnFighters()
{
	DespawnFighters();

	if (FightingGameInstance == nullptr || LeftSpawner == nullptr || RightSpawner == nullptr) return;

	if (FightingGameInstance->LeftFighter != nullptr)
	{
		LeftFighter = LeftSpawner->SpawnFighter(FightingGameInstance->LeftFighter);
		
		if (Player1Controller != nullptr) Player1Controller->Possess(LeftFighter);
	}

	if (FightingGameInstance->RightFighter != nullptr)
	{
		RightFighter = RightSpawner->SpawnFighter(FightingGameInstance->RightFighter);

		if (Player2Controller != nullptr) Player2Controller->Possess(RightFighter);
	}
}

void AFightGameMode::DespawnFighters()
{
	if (LeftFighter != nullptr)
	{
		LeftFighter->Destroy();
		LeftFighter = nullptr;
	}

	if (RightFighter != nullptr)
	{
		RightFighter->Destroy();
		RightFighter = nullptr;
	}
}

void AFightGameMode::StartNewRound()
{
	if (Round < MaxRounds)
	{
		SpawnFighters();
		Timer = RoundTime;
		Round++;
	}

	else
	{
		ReturnToMenu();
	}
}

void AFightGameMode::AddLeftWin()
{
	LeftWins++;
	UE_LOG(LogTemp, Log, TEXT("Added Left Win"));
}

void AFightGameMode::AddRightWin()
{
	RightWins++;
	UE_LOG(LogTemp, Log, TEXT("Added Right Win"));
}
