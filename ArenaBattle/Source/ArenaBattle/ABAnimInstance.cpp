// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance() {
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	//애니메이션 시스템의 틱에서 폰에 접근해 폰의 속력 값을 얻어와야 한다. 이를 위해 제공하는 함수가 TryGetPawnOwner다.
	auto Pawn = TryGetPawnOwner(); //폰에 접근할 때 먼저 폰 객체가 유효한지 점검한다.
	if (::IsValid(Pawn)) {
		CurrentPawnSpeed = Pawn->GetVelocity().Size();	//폰의 속도 크기를 얻어온다.
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsInAir = Character->GetMovementComponent()->IsFalling();	//캐릭터가 떨어지는 중이라면 캐릭터가 공중에 있다는 값이 true가 되게 한다.
		}
	}
}