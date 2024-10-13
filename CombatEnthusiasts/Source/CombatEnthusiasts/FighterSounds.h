// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FighterSounds.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATENTHUSIASTS_API UFighterSounds : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AFighter* Fighter;


public:	
	// Sets default values for this component's properties
	UFighterSounds();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Voice")
	class USoundBase* Voice_Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Voice")
	USoundBase* Voice_TookDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Voice")
	USoundBase* Voice_Intro;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Voice")
	USoundBase* Voice_Win;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Voice")
	USoundBase* Voice_Selected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Body Sounds")
	USoundBase* Body_FootHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Body Sounds")
	USoundBase* Body_FistHit;

	UFUNCTION(BlueprintCallable)
	void PlayFootHitBody();

	UFUNCTION(BlueprintCallable)
	void PlayFistHitBody();

	UFUNCTION(BlueprintCallable)
	void PlayAttackVoice();

	UFUNCTION(BlueprintCallable)
	void PlayTookDamageVoice();

	UFUNCTION(BlueprintCallable)
	void PlayIntroVoice();

	UFUNCTION(BlueprintCallable)
	void PlayWinVoice();
};
