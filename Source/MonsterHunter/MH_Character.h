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

	// 블루프린트 에서의 AnyDamage 함수와 같은 함수 (AActor 클래스로 부터 상속)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// MH_Character 맴버변수 초기화 함수 (생성자에서 사용) 
	virtual void InitializeCharacter();

	// 공격받았을 시 체력 업데이트 해주는 함수 (TakeDamage 함수에서 사용)
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
