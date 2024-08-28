// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"

// Sets default values
AFighter::AFighter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = CreateDefaultSubobject<UHealth>(TEXT("Health"));

	/*LeftHand = CreateDefaultSubobject<ADamager>(TEXT("Left Hand"));

	RightHand = CreateDefaultSubobject<ADamager>(TEXT("Right Hand"));

	LeftFoot = CreateDefaultSubobject<ADamager>(TEXT("Left Foot"));

	RightFoot = CreateDefaultSubobject<ADamager>(TEXT("Right Foot"));*/
}

// Called when the game starts or when spawned
void AFighter::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	TArray<USceneComponent*> Meshes = GetMesh()->GetAttachChildren();
	Meshes.Add(GetMesh());

	for (USceneComponent* ChildMesh : Meshes)
	{
		UE_LOG(LogTemp, Warning, TEXT("ChildMesh %s"), *ChildMesh->GetName());

		if (ChildMesh->DoesSocketExist(FName("Hand_Left")))
		{
			LeftHand = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			LeftHand->SetActorLabel(TEXT("Left Hand"));
			LeftHand->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Hand_Left"));
		}

		if (ChildMesh->DoesSocketExist(FName("Hand_Right")))
		{
			RightHand = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			RightHand->SetActorLabel(TEXT("Right Hand"));
			RightHand->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Hand_Right"));
		}

		if (ChildMesh->DoesSocketExist(FName("Foot_Left")))
		{
			LeftFoot = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			LeftFoot->SetActorLabel(TEXT("Left Foot"));
			LeftFoot->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Foot_Left"));
		}

		if (ChildMesh->DoesSocketExist(FName("Foot_Right")))
		{
			RightFoot = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			RightFoot->SetActorLabel(TEXT("Right Foot"));
			RightFoot->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Foot_Right"));
		}
	}
	
	

}

// Called every frame
void AFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFighter::AddMovement(float Forward)
{
	AddMovementInput(GetActorForwardVector(), Forward * MoveInputSensitivity);
}

