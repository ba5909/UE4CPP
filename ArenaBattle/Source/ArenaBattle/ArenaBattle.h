// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All);	//로깅을 위한 공용 매크로 설정

//ABLOG_S: 코드가 들어있는 파일 이름과 함수, 그리고 라인 정보를 추가해 ArenaBattle 카테고리로 로그를 남긴다. 로그를 사용한 함수의 식행 시점을 파악할 때 유용하다.
//ABLOG: ABLOG_S 정보에 형식 문자열로 추가 정보를 지정해 로그를 남긴다.
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s%s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))