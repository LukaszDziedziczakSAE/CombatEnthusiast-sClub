// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockingComponent.h"

// Sets default values for this component's properties
UBlockingComponent::UBlockingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UBlockingComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UBlockingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (BlockingTiredness > 0 && !bIsBlocking)
	{
		BlockingTiredness = FMath::Clamp(BlockingTiredness - (BlockingTirednessRecoveryRate * DeltaTime), 0.0f, BlockingTirednessMax);

		if (bRecoveryNeeded && BlockingTiredness < RecoveryUneededThreshhold)
		{
			bRecoveryNeeded = false;
		}
	}
}

void UBlockingComponent::SetIsBlocking(bool Blocking)
{
	if (Blocking)
	{
		if (!bRecoveryNeeded)
		{
			bIsBlocking = true;
		}
	}
	else
	{
		bIsBlocking = false;
	}
}

void UBlockingComponent::AddTiredness()
{
	BlockingTiredness = FMath::Clamp(BlockingTiredness + BlockingTirednessPerHit, 0.0f, BlockingTirednessMax);

	if (BlockingTiredness == BlockingTirednessMax)
	{
		bRecoveryNeeded = true;
		bIsBlocking = false;
	}
}

