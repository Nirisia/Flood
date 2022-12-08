// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WaterFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FLOOD_API UWaterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static float BuoyancyCalculation(UMeshComponent* object, float height, EObjectTypeQuery collChannel);
		
	
};
