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
	//애니메이션 블루프린트의 애님 그래프에서 사용할 수 있도록 UPROPERTY 매크로와 EditAnywhere 키워드를 추가했다.
	//블루프린트에 접근하는 방법에 대한 키워드를 추가로 지정해줘야 하는데, 블루프린트에서 접근하는 키워드로 BlueprintReadOnly와 BlueprintReadWrite가 있다.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;
};
