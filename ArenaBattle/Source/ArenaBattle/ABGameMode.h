// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//include "CoreMinimal.h"
#include "ArenaBattle.h" //로그 매크로와 EngineMinimal.h를 참조하도록 CoreMinimal.h를 변경
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
