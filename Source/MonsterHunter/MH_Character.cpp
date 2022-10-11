#include "MH_Character.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "DamageTypeAttack.h"
#include "DamageTypeHeal.h"


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
	//TakeAttackedHp(Damage);
	// TakeHealedHp(Damage);
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentHp);
	
	return Damage;
}

// 공격받았을 시 체력 업데이트 해주는 함수 (TakeDamage 함수에서 사용)
void AMH_Character::TakeAttackedHp(float Damage)
{
	if (!bIsDead)
	{
		if (Damage > CurrentHp)
		{
			CurrentHp = 0.f;
			bIsDead = true;
		}
		else
		{
			CurrentHp -= Damage;
		}
	}
	else
	{
		CurrentHp = 0.f;
		bIsDead = true;
	}
}

// 힐 받았을 시 체력 업데이트 해주는 함수 (TakeDamage 함수에서 사용)
void AMH_Character::TakeHealedHp(float Heal)
{
	if (!bIsDead && MaxHp > CurrentHp)
	{
		float _HealedHp = CurrentHp;
		_HealedHp += Heal;

		if (_HealedHp > MaxHp)
		{
			CurrentHp = MaxHp;
		}
		else
		{
			CurrentHp = _HealedHp;
		}
	}
}

// 공격 시 콜리전에 오버랩된 엑터를 가져와서 그 엑터에 Damage를 주는 함수
void AMH_Character::GiveAttack(AActor* DamagedActor)
{
	UGameplayStatics::ApplyDamage(DamagedActor, AttackPower, GetController(), nullptr, UDamageTypeAttack::StaticClass());
}

// 힐 시 콜리전에 오버랩된 엑터를 가져와서 그 엑터에 Heal을 주는 함수
void AMH_Character::GiveHeal(AActor* HealedActor)
{
	UGameplayStatics::ApplyDamage(HealedActor, HealPower, GetController(), nullptr, UDamageTypeHeal::StaticClass());
}

void AMH_Character::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMH_Character::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

float AMH_Character::GetMaxHp()
{
	return MaxHp;
}

float AMH_Character::GetCurrentHp()
{
	return CurrentHp;
}

bool AMH_Character::GetIsDead()
{
	return bIsDead;
}

// MH_Character 맴버변수 초기화 함수 (생성자에서 사용) 
void AMH_Character::InitializeCharacter()
{
	MaxHp = 200.f;
	CurrentHp = MaxHp;
	AttackPower = 10.f;
	HealPower = 10.f;
	bIsDead = false;
}

