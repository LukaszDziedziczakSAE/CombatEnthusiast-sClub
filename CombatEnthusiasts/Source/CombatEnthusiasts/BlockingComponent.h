// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlockingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATENTHUSIASTS_API UBlockingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBlockingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsBlocking;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bRecoveryNeeded;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float BlockingTiredness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BlockingTirednessMax{100.0f};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BlockingTirednessPerHit{ 35.0f };

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BlockingTirednessRecoveryRate{ 10.0f };

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RecoveryUneededThreshhold{ 65.0f };

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	bool IsBlocking() { return bIsBlocking; }

	UFUNCTION(BlueprintCallable)
	void SetIsBlocking(bool Blocking);

	UFUNCTION(BlueprintCallable)
	void AddTiredness();

	UFUNCTION(BlueprintPure)
	bool RecoveryNeeded() { return bRecoveryNeeded; }

	UFUNCTION(BlueprintPure)
	float TirednessPercentage(){ return BlockingTiredness / BlockingTirednessMax; }
};
