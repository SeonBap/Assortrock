// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MathMianActor.generated.h"

UCLASS()
class AR_UNREAL_API AMathMianActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMathMianActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Backmove(float _Value);

	UFUNCTION(BlueprintCallable)
		void Forwardmove(float _Value);

	UFUNCTION(BlueprintCallable)
		void Leftmove(float _Value);

	UFUNCTION(BlueprintCallable)
		void Rightmove(float _Value);

private:
	float Speed = 500.f;
};
