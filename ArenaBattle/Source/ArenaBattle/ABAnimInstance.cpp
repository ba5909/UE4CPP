// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance() {
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	//�ִϸ��̼� �ý����� ƽ���� ���� ������ ���� �ӷ� ���� ���;� �Ѵ�. �̸� ���� �����ϴ� �Լ��� TryGetPawnOwner��.
	auto Pawn = TryGetPawnOwner(); //���� ������ �� ���� �� ��ü�� ��ȿ���� �����Ѵ�.
	if (::IsValid(Pawn)) {
		CurrentPawnSpeed = Pawn->GetVelocity().Size();	//���� �ӵ� ũ�⸦ ���´�.
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsInAir = Character->GetMovementComponent()->IsFalling();	//ĳ���Ͱ� �������� ���̶�� ĳ���Ͱ� ���߿� �ִٴ� ���� true�� �ǰ� �Ѵ�.
		}
	}
}