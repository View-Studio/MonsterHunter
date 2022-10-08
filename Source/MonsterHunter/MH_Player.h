// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MH_Character.h"
#include "MH_Player.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERHUNTER_API AMH_Player : public AMH_Character
{
	GENERATED_BODY()

public:
	AMH_Player();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
