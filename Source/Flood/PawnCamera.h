// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnCamera.generated.h"

UCLASS()
class FLOOD_API APawnCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnCamera();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	// if the player right clicks to rotate the camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Camera)
	bool CanRotate;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
};
