// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuMode.h"
#include "Kismet/GameplayStatics.h"

void AMenuMode::BeginPlay()
{
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

	if (DefaultFighter != nullptr)
	{
		if (FightingGameInstance->LeftFighter != nullptr) SelectLeftFighter(FightingGameInstance->LeftFighter);
		else SelectLeftFighter(DefaultFighter);

		if (FightingGameInstance->RightFighter != nullptr) SelectRightFighter(FightingGameInstance->RightFighter);
		else SelectRightFighter(DefaultFighter);
	}
	else UE_LOG(LogTemp, Error, TEXT("Missing DefaultFighter Referance"));

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
}

void AMenuMode::SelectLeftFighter(TSubclassOf<AFighter> Fighter)
{
	if (LeftSpawner == nullptr || FightingGameInstance == nullptr) return;
	if (LeftFighter != nullptr) LeftFighter->Destroy();

	LeftFighter = LeftSpawner->SpawnFighter(Fighter);
	FightingGameInstance->LeftFighter = Fighter;

	UE_LOG(LogTemp, Display, TEXT("Selected Left Fighter: %s"), *LeftFighter->GetFighterName());
}

void AMenuMode::SelectRightFighter(TSubclassOf<AFighter> Fighter)
{
	if (RightSpawner == nullptr || FightingGameInstance == nullptr) return;
	if (RightFighter != nullptr) RightFighter->Destroy();

	RightFighter = RightSpawner->SpawnFighter(Fighter);
	FightingGameInstance->RightFighter = Fighter;

	UE_LOG(LogTemp, Display, TEXT("Selected Right Fighter: %s"), *RightFighter->GetFighterName());
}

