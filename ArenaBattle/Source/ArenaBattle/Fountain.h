// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "EngineMinimal.h"	//다양한 엔진 기능이 필요하기 때문에 CoreMinimal.h대신 사용한다.
#include "ArenaBattle.h"	//로깅을 위한 공용 매크로 설정에서
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"	//언리얼 오브젝트 선언의 마지막 #include 구문에 이 헤더 파일을 반드시 선언해야 한다.

UCLASS()	//클래스 선언 매크로: 해당 클래스가 언리얼 오브젝트임을 선언하기 위한 매크로
class ARENABATTLE_API AFountain : public AActor	//접두사 A는 액터를 나타낸다. U는 액터가 아닌 클래스를 나타낸다.
{
	GENERATED_BODY()	//클래스 내부 매크로

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

	UPROPERTY(VisibleAnywhere)	//VisibleAnywhere는 디테일 윈도우에서 컴포넌트를 편집하기 위해.
		/*메모리 관리용 언리얼 매크로. 
		포인터로 선언했으므로 메모리를 동적으로 할당해 대입한 것이다. 
		매크로를 이용해 메모리 자동 소멸 기능을 제공한다.
		언리얼 오브젝트에서만 사용할 수 있는 기능이다.
		잊지 말아야 한다.*/
	UStaticMeshComponent* Body;		//새로 추가한 선언 구문

	UPROPERTY(VisibleAnywhere) //메모리 관리용 언리얼 매크로
	UStaticMeshComponent* Water;	//새로 추가한 선언 구문

	UPROPERTY(VisibleAnywhere)
		UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* Splash;

	//UPROPERTY(VisibleAnywhere)
	//	int32 ID;					//멤버 변수
	//VisibleAnywhere는 디테일 윈도우에서 컴포넌트를 편집하기 위해 사용할 수 있지만 해당 객체를 다른 객체로 변경은 불가하다.
	//ID는 0이며 0을 편집할 수 없다.

	UPROPERTY(EditAnywhere, Category=ID)	//에디터에서 편집 가능한 키워드. Category=분류명
		int32 ID;					//멤버 변수

	UPROPERTY(VisibleAnywhere)
		URotatingMovementComponent* Movement;	//지정한 속도로 액터를 회전시킨다

private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;
};
