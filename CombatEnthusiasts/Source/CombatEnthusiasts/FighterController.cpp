// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterController.h"


void AFighterController::BeginPlay()
{
	Super::BeginPlay();

	
}

void AFighterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	Fighter = Cast<AFighter>(aPawn);
	UE_LOG(LogTemp, Display, TEXT("%s possessed %s"), *GetName(), *Fighter->GetFighterName());
}

void AFighterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer();

	if (InputSubsystem != nullptr && InputMapping != nullptr)
	{
		InputSubsystem->ClearAllMappings();
		InputSubsystem->AddMappingContext(InputMapping, 0);
	}
	else if (InputSubsystem == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Missing Input Subsystem Referance"), *GetName());
		return;
	}

	else if (InputMapping == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Missing Input Mapping Referance"), *GetName());
		return;
	}

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	if (Input != nullptr)
	{
		Input->BindAction(IA_Movement, ETriggerEvent::Triggered, this, &AFighterController::Movement);
		Input->BindAction(IA_Movement, ETriggerEvent::Completed, this, &AFighterController::MovementEnd);
		Input->BindAction(IA_Punch, ETriggerEvent::Triggered, this, &AFighterController::Punch);
		Input->BindAction(IA_Kick, ETriggerEvent::Triggered, this, &AFighterController::Kick);
		Input->BindAction(IA_Block, ETriggerEvent::Triggered, this, &AFighterController::BlockStart);
		Input->BindAction(IA_Block, ETriggerEvent::Completed, this, &AFighterController::BlockEnd);
		Input->BindAction(IA_Run, ETriggerEvent::Triggered, this, &AFighterController::RunStart);
		Input->BindAction(IA_Run, ETriggerEvent::Completed, this, &AFighterController::RunEnd);
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Missing Input Referance"));
	}
}

void AFighterController::Movement(const FInputActionValue& Value)
{
	if (Fighter == nullptr) return;

	Fighter->MovementInput = Value.Get<FVector2D>();
}

void AFighterController::MovementEnd(const FInputActionValue& Value)
{
	if (Fighter == nullptr) return;

	Fighter->MovementInput = FVector2D::Zero();
}

void AFighterController::Kick(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->BeginAttack(0);
	}
}

void AFighterController::Punch(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->BeginAttack(1);
	}
}

void AFighterController::BlockStart(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->SetIsBlocking(true);
	}
}

void AFighterController::BlockEnd(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->SetIsBlocking(false);
	}
}

void AFighterController::RunStart(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->SetIsRunning(true);
	}
}

void AFighterController::RunEnd(const FInputActionValue& Value)
{
	if (Fighter != nullptr)
	{
		Fighter->SetIsRunning(false);
	}
}
