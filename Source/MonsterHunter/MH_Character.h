// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MH_Character.generated.h"

UCLASS()
class MONSTERHUNTER_API AMH_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AMH_Character();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	void InitializeCharacter();
	void TakeAttackedDamage(float Damage);

public:
	float GetMaxHp();
	float GetCurrentHp();

protected:
	float MaxHp;
	float CurrentHp;
};
