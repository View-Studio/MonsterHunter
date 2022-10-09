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

// 블루프린트 에서의 AnyDamage 함수와 같은 함수 (AActor 클래스로 부터 상속)
float AMH_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// 분기문 써서 힐 받았을 때, 공격 받았을 때 실행할 로직 나눌 계획
	TakeAttackedDamage(Damage);
	
	return Damage;
}

// MH_Character 맴버변수 초기화 함수 (생성자에서 사용) 
void AMH_Character::InitializeCharacter()
{
	MaxHp = 200.f;
	CurrentHp = MaxHp;
}

// 공격받았을 시 체력 업데이트 해주는 함수 (TakeDamage 함수에서 사용)
void AMH_Character::TakeAttackedDamage(float Damage)
{
	if (CurrentHp > 0.f)
	{
		if (Damage > CurrentHp)
		{
			CurrentHp = 0.f;
		}
		else
		{
			CurrentHp -= Damage;
		}
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

