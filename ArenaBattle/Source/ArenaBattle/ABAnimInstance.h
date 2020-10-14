// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	//�ִϸ��̼� �������Ʈ�� �ִ� �׷������� ����� �� �ֵ��� UPROPERTY ��ũ�ο� EditAnywhere Ű���带 �߰��ߴ�.
	//�������Ʈ�� �����ϴ� ����� ���� Ű���带 �߰��� ��������� �ϴµ�, �������Ʈ���� �����ϴ� Ű����� BlueprintReadOnly�� BlueprintReadWrite�� �ִ�.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;
};
