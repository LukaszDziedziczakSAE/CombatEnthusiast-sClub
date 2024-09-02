// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"
#include "Fighter.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100;
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();

	Fighter = Cast<AFighter>(GetOwner());

	ResetHealth();
	
}


// Called every frame
void UHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealth::ResetHealth()
{
	CurretHealth = MaxHealth;
}

void UHealth::TakeHealth(float Amount)
{
	if (Fighter == nullptr) return;

	if (Fighter->GetIsBlocking())
	{
		return;
	}

	else // fighter is not blocking
	{
		CurretHealth = FMath::Clamp(CurretHealth - Amount, 0, MaxHealth);
	}

	if (CurretHealth > 0)
	{
		Fighter->BeginImpact();
	}
	else
	{
		Fighter->Death();
	}

	
}

void UHealth::RestorHealth(float Amount)
{
	CurretHealth = FMath::Clamp(CurretHealth + Amount, 0, MaxHealth);
}

