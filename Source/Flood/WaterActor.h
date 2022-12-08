// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaterActor.generated.h"

UCLASS()
class FLOOD_API AWaterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaterActor();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float waterHeight = 0.f;

	UPROPERTY(EditAnywhere)
	bool isStill = false;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
