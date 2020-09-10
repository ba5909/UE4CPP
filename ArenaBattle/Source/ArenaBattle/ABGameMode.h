// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//include "CoreMinimal.h"
#include "ArenaBattle.h" //�α� ��ũ�ο� EngineMinimal.h�� �����ϵ��� CoreMinimal.h�� ����
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()

		AABGameMode();

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};