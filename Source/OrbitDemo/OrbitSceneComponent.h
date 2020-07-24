// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OrbitSceneComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ORBITDEMO_API UOrbitSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitSceneComponent();

	//参数1 起始位置
	UPROPERTY(EditAnywhere)
		FVector StartPos;

	//参数2 水平运行的角速度,角度
	UPROPERTY(EditAnywhere)
		float AngularVelocity;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//z轴到当前位置的水平方向与x轴的夹角,顺时针为正,弧度
	UPROPERTY(VisibleAnywhere)
	float Angle;

	//运行平面的高度 编辑器内可调试
	UPROPERTY(EditAnywhere)
	float Height;

	//运行的半径 编辑器内可调试
	UPROPERTY(EditAnywhere)
	float Radius;

	FVector NewLocation;
	FRotator NewRotator;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
};