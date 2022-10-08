// Fill out your copyright notice in the Description page of Project Settings.


#include "MH_Player.h"

AMH_Player::AMH_Player()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMH_Player::BeginPlay()
{
	Super::BeginPlay();
}

void AMH_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
