// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATENTHUSIASTS_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurretHealth;

	class AFighter* Fighter;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void ResetHealth();

	UFUNCTION(BlueprintCallable)
	void TakeHealth(float Amount);

	UFUNCTION(BlueprintCallable)
	void RestorHealth(float Amount);

	UFUNCTION(BlueprintPure)
	float GetCurretHealth() { return CurretHealth; }

	UFUNCTION(BlueprintPure)
	float GetMaxHealth() { return MaxHealth; }

	UFUNCTION(BlueprintPure)
	float GetHealthPercentage() { return CurretHealth / MaxHealth; }
};
