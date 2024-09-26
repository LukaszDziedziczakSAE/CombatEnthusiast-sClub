// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControlActorComponent.h"
#include "FightGameMode.h"

// Sets default values for this component's properties
UCameraControlActorComponent::UCameraControlActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCameraControlActorComponent::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetOwner()->GetActorLocation();
	FightGameMode = Cast<AFightGameMode>(GetWorld()->GetAuthGameMode());
	
}


// Called every frame
void UCameraControlActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (FightGameMode == nullptr) return;

	//UE_LOG(LogTemp, Warning, TEXT("LeftFighter: %f, "), FightGameMode->LeftFighter->GetActorLocation().Y);
	float FightAxis = FightGameMode->LeftFighter->GetActorLocation().X;
	float LeftFighterLocation = FightGameMode->LeftFighter->GetActorLocation().Y;
	float RightFighterLocation = FightGameMode->RightFighter->GetActorLocation().Y;
	float DistanceBetweenFighters;
	float FighterMidPoint;
	if (LeftFighterLocation > RightFighterLocation)
	{
		DistanceBetweenFighters = LeftFighterLocation - RightFighterLocation;
	}
	else
	{
		DistanceBetweenFighters = RightFighterLocation - LeftFighterLocation;
	}


	FighterMidPoint = (DistanceBetweenFighters / 2) + LeftFighterLocation;
	//UE_LOG(LogTemp, Warning, TEXT("Midpoint: %f"), FighterMidPoint);

	FVector CameraLocation = GetOwner()->GetActorLocation();
	CameraLocation.Y = FighterMidPoint;
	CameraLocation.X = FightAxis - (MinDistanceToFighers + (DistanceBetweenFighters* DistanceMultiplier));

	FVector LerpedLocation = FMath::Lerp(GetOwner()->GetActorLocation(), CameraLocation, LerpFactor);

	GetOwner()->SetActorLocation(LerpedLocation);
}

