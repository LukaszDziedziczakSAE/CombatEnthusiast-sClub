// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EFightingStyle.h"
#include "FighterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATENTHUSIASTS_API UFighterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AFighter* Fighter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EFightingStyle> FightingStyle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsBlocking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<enum EFighterSide> FighterSide;

	UFUNCTION(BlueprintCallable)
	void Initilise();

	UFUNCTION(BlueprintCallable)
	void UpdateIsBlocking();

	UFUNCTION(BlueprintCallable)
	void UpdateSpeed();
};
