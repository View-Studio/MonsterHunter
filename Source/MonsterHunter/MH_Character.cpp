


#include "MH_Character.h"


AMH_Character::AMH_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	InitializeCharacter();
}


void AMH_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMH_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMH_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMH_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	TakeAttackedDamage(Damage);
	
	return Damage;
}

void AMH_Character::InitializeCharacter()
{
	MaxHp = 200.f;
	CurrentHp = MaxHp;
}

void AMH_Character::TakeAttackedDamage(float Damage)
{
	if (CurrentHp > 0.f)
	{
		CurrentHp -= Damage;
	}
	else
	{
		CurrentHp = 0.f;
	}
}

float AMH_Character::GetMaxHp()
{
	return MaxHp;
}

float AMH_Character::GetCurrentHp()
{
	return CurrentHp;
}

