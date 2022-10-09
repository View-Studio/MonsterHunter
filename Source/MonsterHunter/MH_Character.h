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

	// �������Ʈ ������ AnyDamage �Լ��� ���� �Լ� (AActor Ŭ������ ���� ���)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// MH_Character �ɹ����� �ʱ�ȭ �Լ� (�����ڿ��� ���) 
	virtual void InitializeCharacter();

	// ���ݹ޾��� �� ü�� ������Ʈ ���ִ� �Լ� (TakeDamage �Լ����� ���)
	void	TakeAttackedHp(float Damage);
	void	TakeHealHp(float Heal);

	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);

public:
	float	GetMaxHp();
	float	GetCurrentHp();
	bool	GetIsDead();

protected:
	float	MaxHp;
	float	CurrentHp;
	bool	bIsDead;

};
