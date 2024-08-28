// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Health.h"
#include "Damager.h"
#include "Fighter.generated.h"

UCLASS()
class COMBATENTHUSIASTS_API AFighter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFighter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MoveInputSensitivity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UHealth* Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADamager* LeftHand;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADamager* RightHand;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADamager* LeftFoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ADamager* RightFoot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ADamager> Damager;

private:
	UFUNCTION(BlueprintCallable)
	void AddMovement(float Forward);

};
