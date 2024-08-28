// Fill out your copyright notice in the Description page of Project Settings.


#include "Damager.h"

// Sets default values
ADamager::ADamager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(Sphere);

	Sphere->SetCollisionProfileName(FName("NoCollision"), true);

	bReplicates = true;
	Sphere->SetSphereRadius(15);
}

// Called when the game starts or when spawned
void ADamager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

