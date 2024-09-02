// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFighter::AFighter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = CreateDefaultSubobject<UHealth>(TEXT("Health"));
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
		//UE_LOG(LogTemp, Warning, TEXT("ChildMesh %s"), *ChildMesh->GetName());

		if (ChildMesh->DoesSocketExist(FName("Hand_Left")) && LeftHand == nullptr)
		{
			LeftHand = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			//LeftHand->SetActorLabel(TEXT("Left Hand"));
			LeftHand->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Hand_Left"));
		}

		if (ChildMesh->DoesSocketExist(FName("Hand_Right")) && RightHand == nullptr)
		{
			RightHand = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			//RightHand->SetActorLabel(TEXT("Right Hand"));
			RightHand->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Hand_Right"));
		}

		if (ChildMesh->DoesSocketExist(FName("Foot_Left")) && LeftFoot == nullptr)
		{
			LeftFoot = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			//LeftFoot->SetActorLabel(TEXT("Left Foot"));
			LeftFoot->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Foot_Left"));
		}

		if (ChildMesh->DoesSocketExist(FName("Foot_Right")) && RightFoot == nullptr)
		{
			RightFoot = GetWorld()->SpawnActor<ADamager>(Damager, GetActorLocation(), GetActorRotation(), SpawnParams);
			//RightFoot->SetActorLabel(TEXT("Right Foot"));
			RightFoot->AttachToComponent(ChildMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Foot_Right"));
		}
	}
	
	CurrentAttack = -1;

	if (LeftHand == nullptr) UE_LOG(LogTemp, Error, TEXT("% s missing Left Hand Damager"), *GetName());
	if (RightHand == nullptr) UE_LOG(LogTemp, Error, TEXT("% s missing Right Hand Damager"), *GetName());
	if (LeftFoot == nullptr) UE_LOG(LogTemp, Error, TEXT("% s missing Left Foot Damager"), *GetName());
	if (RightFoot == nullptr) UE_LOG(LogTemp, Error, TEXT("% s missing Right Foot Damager"), *GetName());

	GetCharacterMovement()->MaxWalkSpeed = WalkingSpeed;
}

// Called every frame
void AFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovementInput.X != 0)
	{
		AddMovement(MovementInput.X);
	}

}

// Called to bind functionality to input
void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFighter::BeginAttack(int MoveIndex)
{
	if (CurrentAttack != -1 || IsBlocking) return;

	CurrentAttack = MoveIndex;

	switch (Moves[CurrentAttack].BodyPart)
	{
	case EMoveBodyPart::LeftHand:
		LeftHand->BeginDamaging();
		break;

	case EMoveBodyPart::RightHand:
		RightHand->BeginDamaging();
		break;

	case EMoveBodyPart::LeftFoot:
		LeftFoot->BeginDamaging();
		break;

	case EMoveBodyPart::RightFoot:
		RightFoot->BeginDamaging();
		break;

	case EMoveBodyPart::BothHands:
		LeftHand->BeginDamaging();
		RightHand->BeginDamaging();
		break;

	default:
		break;
	}
}

void AFighter::CompleteAttack()
{
	switch (Moves[CurrentAttack].BodyPart)
	{
	case EMoveBodyPart::LeftHand:
		LeftHand->EndDamaging();
		break;

	case EMoveBodyPart::RightHand:
		RightHand->EndDamaging();
		break;

	case EMoveBodyPart::LeftFoot:
		LeftFoot->EndDamaging();
		break;

	case EMoveBodyPart::RightFoot:
		RightFoot->EndDamaging();
		break;

	case EMoveBodyPart::BothHands:
		LeftHand->EndDamaging();
		RightHand->EndDamaging();
		break;

	default:
		break;
	}


	CurrentAttack = -1;
}

UAnimMontage* AFighter::GetCurrentAttackMontage()
{
	if (CurrentAttack == -1) return nullptr;
	return Moves[CurrentAttack].AnimMontage;
}

float AFighter::GetCurretAttackDamage()
{
	if (CurrentAttack == -1) return 0;
	return Moves[CurrentAttack].Damage;
}

void AFighter::BeginImpact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("%s BeginImpact_Implementation"), *GetName());
	CurrentAttack = -2;
}

void AFighter::CompleteImpact()
{
	CurrentAttack = -1;
}

void AFighter::SetIsBlocking(bool Blocking)
{
	IsBlocking = Blocking;
}

void AFighter::SetIsRunning(bool Running)
{
	IsRunning = Running;

	GetCharacterMovement()->MaxWalkSpeed = IsRunning ? RunningSpeed : WalkingSpeed;
}

void AFighter::AddMovement(float Forward)
{
	if (CurrentAttack != -1 || IsBlocking) return;

	AddMovementInput(GetActorForwardVector(), Forward * MoveInputSensitivity);
}

void AFighter::Death_Implementation()
{
	
}

