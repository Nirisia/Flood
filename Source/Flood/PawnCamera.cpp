// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnCamera.h"
#include "Components/InputComponent.h"

// Sets default values
APawnCamera::APawnCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

}

// Called when the game starts or when spawned
void APawnCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnCamera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawnCamera::TurnAtRate);
	//PlayerInputComponent->BindAxis("TurnRate", this, &APawnCamera::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawnCamera::LookUpAtRate);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &APawnCamera::LookUpAtRate);
}

void APawnCamera::TurnAtRate(float Rate)
{
	if (!CanRotate)
		return;
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APawnCamera::LookUpAtRate(float Rate)
{
	if (!CanRotate)
		return;
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

