// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents() {
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::OnPossess(APawn* aPawn) {
	ABLOG_S(Warning);
	Super::OnPossess(aPawn);//4.22부터 Possess가 OnPossess로 바뀐 것 같다.
}