// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbitSceneComponent.h"

// Sets default values for this component's properties
UOrbitSceneComponent::UOrbitSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOrbitSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Angle = atan2f(StartPos.Y, StartPos.X);

	Height = StartPos.Z;

	Radius = sqrtf(StartPos.Y * StartPos.Y + StartPos.X * StartPos.X);

	NewLocation.X = Radius * cosf(Angle);
	NewLocation.Y = Radius * sinf(Angle);
	NewLocation.Z = Height;

	NewRotator.Pitch = 0;
	NewRotator.Roll = 0;
	NewRotator.Yaw = Angle;
}


// Called every frame
void UOrbitSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Angle += DeltaTime * FMath::DegreesToRadians(AngularVelocity);
	
	Angle = Angle - (Angle > 2 * PI) * 2 * PI;

	NewLocation.X = Radius * cosf(Angle);
	NewLocation.Y = Radius * sinf(Angle);
	NewLocation.Z = Height;

	NewRotator.Yaw = FMath::RadiansToDegrees(Angle);

	SetRelativeLocationAndRotation(NewLocation, NewRotator);
}

