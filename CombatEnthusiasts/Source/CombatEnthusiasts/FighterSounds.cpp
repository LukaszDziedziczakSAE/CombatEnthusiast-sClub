// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterSounds.h"
#include "Fighter.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UFighterSounds::UFighterSounds()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFighterSounds::BeginPlay()
{
	Super::BeginPlay();

	Fighter = Cast<AFighter>(GetOwner());
	
}


// Called every frame
void UFighterSounds::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFighterSounds::PlayFootHitBody()
{
	if (!IsValid(Body_FootHit)) return;

	Fighter->AudioBody->SetSound(Body_FootHit);
	Fighter->AudioBody->Play();
}

void UFighterSounds::PlayFistHitBody()
{
	if (!IsValid(Body_FistHit)) return;

	Fighter->AudioBody->SetSound(Body_FistHit);
	Fighter->AudioBody->Play();
}

void UFighterSounds::PlayAttackVoice()
{
	if (!IsValid(Voice_Attack)) return;

	Fighter->AudioVoice->SetSound(Voice_Attack);
	Fighter->AudioVoice->Play();
}

void UFighterSounds::PlayTookDamageVoice()
{
	if (!IsValid(Voice_TookDamage)) return;

	Fighter->AudioVoice->SetSound(Voice_TookDamage);
	Fighter->AudioVoice->Play();
}

void UFighterSounds::PlayIntroVoice()
{
	if (!IsValid(Voice_Intro)) return;

	Fighter->AudioVoice->SetSound(Voice_Intro);
	Fighter->AudioVoice->Play();
}

void UFighterSounds::PlayWinVoice()
{
	if (!IsValid(Voice_Win)) return;

	Fighter->AudioVoice->SetSound(Voice_Win);
	Fighter->AudioVoice->Play();
}

