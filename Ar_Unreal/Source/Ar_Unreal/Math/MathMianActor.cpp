// Fill out your copyright notice in the Description page of Project Settings.


#include "MathMianActor.h"

// Sets default values
AMathMianActor::AMathMianActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMathMianActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMathMianActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMathMianActor::Backmove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::BackwardVector * GetWorld()->DeltaTimeSeconds * Speed);
}

void AMathMianActor::Forwardmove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::ForwardVector * GetWorld()->DeltaTimeSeconds * Speed);
}

void AMathMianActor::Leftmove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector * GetWorld()->DeltaTimeSeconds * Speed);
}

void AMathMianActor::Rightmove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector * GetWorld()->DeltaTimeSeconds * Speed);
}

