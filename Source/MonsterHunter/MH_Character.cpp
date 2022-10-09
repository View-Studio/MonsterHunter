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

// �������Ʈ ������ AnyDamage �Լ��� ���� �Լ� (AActor Ŭ������ ���� ���)
float AMH_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// �б⹮ �Ἥ �� �޾��� ��, ���� �޾��� �� ������ ���� ���� ��ȹ
	TakeAttackedDamage(Damage);
	
	return Damage;
}

// MH_Character �ɹ����� �ʱ�ȭ �Լ� (�����ڿ��� ���) 
void AMH_Character::InitializeCharacter()
{
	MaxHp = 200.f;
	CurrentHp = MaxHp;
}

// ���ݹ޾��� �� ü�� ������Ʈ ���ִ� �Լ� (TakeDamage �Լ����� ���)
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

