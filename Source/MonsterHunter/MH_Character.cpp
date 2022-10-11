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

// �������Ʈ ������ AnyDamage �Լ��� ���� �Լ� (AActor Ŭ������ ���� ���)
float AMH_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// �б⹮ �Ἥ �� �޾��� ��, ���� �޾��� �� ������ ���� ���� ��ȹ
	//TakeAttackedHp(Damage);
	// TakeHealedHp(Damage);
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentHp);
	
	return Damage;
}

// ���ݹ޾��� �� ü�� ������Ʈ ���ִ� �Լ� (TakeDamage �Լ����� ���)
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

// �� �޾��� �� ü�� ������Ʈ ���ִ� �Լ� (TakeDamage �Լ����� ���)
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

// ���� �� �ݸ����� �������� ���͸� �����ͼ� �� ���Ϳ� Damage�� �ִ� �Լ�
void AMH_Character::GiveAttack(AActor* DamagedActor)
{
	UGameplayStatics::ApplyDamage(DamagedActor, AttackPower, GetController(), nullptr, UDamageTypeAttack::StaticClass());
}

// �� �� �ݸ����� �������� ���͸� �����ͼ� �� ���Ϳ� Heal�� �ִ� �Լ�
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

// MH_Character �ɹ����� �ʱ�ȭ �Լ� (�����ڿ��� ���) 
void AMH_Character::InitializeCharacter()
{
	MaxHp = 200.f;
	CurrentHp = MaxHp;
	AttackPower = 10.f;
	HealPower = 10.f;
	bIsDead = false;
}

