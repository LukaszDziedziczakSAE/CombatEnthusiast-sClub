// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterController.h"
//#include "EnhancedInputSubsystems.h"


//void AFighterController::BeginPlay()
//{
//	/*UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
//
//	if (Subsystem != nullptr && InputMapping != nullptr)
//	{
//		Subsystem->ClearAllMappings();
//		Subsystem->AddMappingContext(InputMapping, 0);
//	}
//	else if (Subsystem != nullptr)
//	{
//		UE_LOG(LogTemp, Error, TEXT("%s Missing Subsystem Referance"), *GetName());
//		return;
//	}
//
//	else if (InputMapping != nullptr)
//	{
//		UE_LOG(LogTemp, Error, TEXT("%s Missing InputMapping Referance"), *GetName());
//		return;
//	}
//
//	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
//	if (Input != nullptr)
//	{
//		Input->BindAction(IA_Punch, ETriggerEvent::Triggered, this, &AFighterController::Punch);
//	}
//
//	else
//	{
//		UE_LOG(LogTemp, Error, TEXT("Missing Input Referance"));
//	}*/
//}

void AFighterController::OnPossess(APawn* aPawn)
{
	Fighter = Cast<AFighter>(aPawn);
	UE_LOG(LogTemp, Display, TEXT("%s possessed %s"), *GetName(), *Fighter->GetFighterName());
}

//void AFighterController::Movement(const FInputActionValue& Value)
//{
//}
//
//void AFighterController::Kick(const FInputActionValue& Value)
//{
//}
//
//void AFighterController::Punch(const FInputActionValue& Value)
//{
//	if (Fighter != nullptr)
//	{
//		Fighter->BeginAttack(1);
//	}
//}
//
//void AFighterController::BlockStart(const FInputActionValue& Value)
//{
//}
//
//void AFighterController::BlockEnd(const FInputActionValue& Value)
//{
//}
//
//void AFighterController::RunStart(const FInputActionValue& Value)
//{
//}
//
//void AFighterController::RunEnd(const FInputActionValue& Value)
//{
//}
