// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MathGameMode.generated.h"

/**
 * 
 */
UENUM(Blueprintint)
enum class OtherState : uint8
{
	Idle,
	LocalTrace,
	WorldTrace,
	PTrace,
	Jump,
	Look,
	AngleRot,
	AngleLook,
	AngleAccLook,
};

UCLASS()
class AR_UNREAL_API AMathGameMode : public AGameMode
{
	GENERATED_BODY()
	
};
