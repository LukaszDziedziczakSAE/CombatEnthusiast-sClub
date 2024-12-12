// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterAnimInstance.h"
#include "Fighter.h"
#include "BlockingComponent.h"

void UFighterAnimInstance::Initilise()
{
	Fighter = Cast<AFighter>(TryGetPawnOwner());
	FightingStyle = Fighter->GetFightingStyle();
}

void UFighterAnimInstance::UpdateIsBlocking()
{
	if (!IsValid(Fighter)) return;

	bIsBlocking = Fighter->Blocking()->IsBlocking();
}

void UFighterAnimInstance::UpdateSpeed()
{
	if (!IsValid(Fighter)) return;

	if (Fighter->MovementInput.X == 0)
	{
		Speed = 0;
	}

	else
	{
		if (Fighter->GetSide() == EFighterSide::Left)
		{
			if (Fighter->MovementInput.X > 0)
			{
				Speed = Fighter->GetIsRunning() ? 2 : 1;
			}
			else
			{
				Speed = Fighter->GetIsRunning() ? -2 : -1;
			}
		}

		else if (Fighter->GetSide() == EFighterSide::Right)
		{
			if (Fighter->MovementInput.X < 0)
			{
				Speed = Fighter->GetIsRunning() ? 2 : 1;
			}
			else
			{
				Speed = Fighter->GetIsRunning() ? -2 : -1;
			}
		}

	}
}
