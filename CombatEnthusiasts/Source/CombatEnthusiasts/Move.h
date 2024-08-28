// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Move.generated.h"

UENUM()
enum EMoveBodyPart
{
	none,
	LeftHand,
	RightHand,
	LeftFoot,
	RightFoot,
	BothHands
};

USTRUCT(BlueprintType)
struct FMove
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EMoveBodyPart> BodyPart;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* AnimMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage;
};
