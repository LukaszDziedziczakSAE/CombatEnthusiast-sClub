// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fighter.h"
#include "Spawner.generated.h"

UCLASS()
class COMBATENTHUSIASTS_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EFighterSide> Side;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	AFighter* SpawnFighter(TSubclassOf<AFighter> Fighter);

	UFUNCTION()
	TEnumAsByte<EFighterSide> GetSide() { return Side; }
};
