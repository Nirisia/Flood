// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterActor.h"

// Sets default values
AWaterActor::AWaterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaterActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWaterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isStill)
	{
		FVector currScale = GetActorScale();

		currScale.Z = (sinf(GetWorld()->GetTimeSeconds()) + 2.f) * 2.f;
		SetActorScale3D(currScale);
	}
	//waterHeight = (currScale.Z / 2.f) + GetActorLocation().Z;
	FVector origin;
	FVector extent;
	GetActorBounds(true, origin, extent);
	waterHeight = origin.Z + extent.Z;
}

