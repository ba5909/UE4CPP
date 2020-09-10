// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "EngineMinimal.h"	//�پ��� ���� ����� �ʿ��ϱ� ������ CoreMinimal.h��� ����Ѵ�.
#include "ArenaBattle.h"	//�α��� ���� ���� ��ũ�� ��������
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"	//�𸮾� ������Ʈ ������ ������ #include ������ �� ��� ������ �ݵ�� �����ؾ� �Ѵ�.

UCLASS()	//Ŭ���� ���� ��ũ��: �ش� Ŭ������ �𸮾� ������Ʈ���� �����ϱ� ���� ��ũ��
class ARENABATTLE_API AFountain : public AActor	//���λ� A�� ���͸� ��Ÿ����. U�� ���Ͱ� �ƴ� Ŭ������ ��Ÿ����.
{
	GENERATED_BODY()	//Ŭ���� ���� ��ũ��

public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)	//VisibleAnywhere�� ������ �����쿡�� ������Ʈ�� �����ϱ� ����.
		/*�޸� ������ �𸮾� ��ũ��. 
		�����ͷ� ���������Ƿ� �޸𸮸� �������� �Ҵ��� ������ ���̴�. 
		��ũ�θ� �̿��� �޸� �ڵ� �Ҹ� ����� �����Ѵ�.
		�𸮾� ������Ʈ������ ����� �� �ִ� ����̴�.
		���� ���ƾ� �Ѵ�.*/
	UStaticMeshComponent* Body;		//���� �߰��� ���� ����

	UPROPERTY(VisibleAnywhere) //�޸� ������ �𸮾� ��ũ��
	UStaticMeshComponent* Water;	//���� �߰��� ���� ����

	UPROPERTY(VisibleAnywhere)
		UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* Splash;

	//UPROPERTY(VisibleAnywhere)
	//	int32 ID;					//��� ����
	//VisibleAnywhere�� ������ �����쿡�� ������Ʈ�� �����ϱ� ���� ����� �� ������ �ش� ��ü�� �ٸ� ��ü�� ������ �Ұ��ϴ�.
	//ID�� 0�̸� 0�� ������ �� ����.

	UPROPERTY(EditAnywhere, Category=ID)	//�����Ϳ��� ���� ������ Ű����. Category=�з���
		int32 ID;					//��� ����

	UPROPERTY(VisibleAnywhere)
		URotatingMovementComponent* Movement;	//������ �ӵ��� ���͸� ȸ����Ų��

private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;
};
