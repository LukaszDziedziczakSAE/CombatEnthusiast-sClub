// Fill out your copyright notice in the Description page of Project Settings.


#include "Damager.h"
#include "Fighter.h"
#include "FighterSounds.h"

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

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADamager::OnOverlapBegin);
	
}

void ADamager::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsDamaging || OtherActor == GetOwner()) return;

	EndDamaging();

	//UE_LOG(LogTemp, Warning, TEXT("Overlap %s"), *OtherActor->GetName());
	AFighter* OwnerFighter = Cast<AFighter>(GetOwner());
	AFighter* OtherFighter = Cast<AFighter>(OtherActor);

	if (OwnerFighter == nullptr || OtherFighter == nullptr) return;

	OtherFighter->Health->TakeHealth(OwnerFighter->GetCurretAttackDamage());
	
	OtherFighter->Sounds->PlayTookDamageVoice();

	OtherFighter->Sounds->PlayFistHitBody();
}

// Called every frame
void ADamager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamager::BeginDamaging()
{
	Sphere->SetCollisionProfileName(FName("OverlapAll"), true);
	//UE_LOG(LogTemp, Warning, TEXT("%s BeginDamaging"), *GetName());
	IsDamaging = true;
}

void ADamager::EndDamaging()
{
	if (!IsDamaging) return;

	Sphere->SetCollisionProfileName(FName("NoCollision"), true);
	//UE_LOG(LogTemp, Warning, TEXT("%s EndDamaging"), *GetName());
	IsDamaging = false;
}

