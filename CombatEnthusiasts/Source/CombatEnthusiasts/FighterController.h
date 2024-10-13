// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Fighter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "FighterController.generated.h"

UCLASS()
class COMBATENTHUSIASTS_API AFighterController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* aPawn) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AFighter* Fighter;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Movement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Kick1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Kick2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Punch1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Punch2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Block;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Run;

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Movement(const FInputActionValue& Value);

	UFUNCTION()
	void MovementEnd(const FInputActionValue& Value);

	UFUNCTION()
	void Kick1(const FInputActionValue& Value);

	UFUNCTION()
	void Kick2(const FInputActionValue& Value);

	UFUNCTION()
	void Punch1(const FInputActionValue& Value);

	UFUNCTION()
	void Punch2(const FInputActionValue& Value);

	UFUNCTION()
	void BlockStart(const FInputActionValue& Value);

	UFUNCTION()
	void BlockEnd(const FInputActionValue& Value);

	UFUNCTION()
	void RunStart(const FInputActionValue& Value);

	UFUNCTION()
	void RunEnd(const FInputActionValue& Value);
};
