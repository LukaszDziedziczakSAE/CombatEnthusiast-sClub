// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraControlActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATENTHUSIASTS_API UCameraControlActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraControlActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AFightGameMode* FightGameMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector StartingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinDistanceToFighers{ 320.0f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DistanceMultiplier{ 0.65f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float LerpFactor{ 0.05f };

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
