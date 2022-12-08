// Fill out your copyright notice in the Description page of Project Settings.

#include "WaterFunctionLibrary.h"

#include "DrawDebugHelpers.h"
#include "WaterActor.h"

float UWaterFunctionLibrary::BuoyancyCalculation(UMeshComponent* objectMesh, float height, EObjectTypeQuery collChannel)
{

 	FVector pos =  objectMesh->GetOwner()->GetActorLocation();
 	
 	FVector vecArea = objectMesh->Bounds.BoxExtent * 2.f;
	float area = vecArea.X * vecArea.Y * vecArea.Z;
	FVector vecForce = FVector::ZeroVector;
	vecForce.Z -= objectMesh->GetMass() * 1000.f ;//* objectMesh->GetWorld()->GetDeltaSeconds();
	// -> adding deltatime breaks the physics

	objectMesh->AddForce(vecForce, NAME_None, true);

	TArray<AActor*> actors;
	objectMesh->GetOverlappingActors(actors);
    for (auto ovlpActors : actors)
    {
    	AWaterActor* water = Cast<AWaterActor>(ovlpActors); 
	    if (IsValid(water))
	    {
	    	float diff = water->waterHeight - pos.Z;
	    	if (diff < -30.f)
	    	{
	    		objectMesh->AddForce(vecForce, NAME_None, true);
	    		continue;
	    	}
	    	if (diff <= 0.f && diff >= -30.f)
	    		continue;
	    	float addedForce = ((water->waterHeight - pos.Z) * area / 1000.f) ;//* objectMesh->GetMass()/10.f;
	    		
	    	vecForce.Z = addedForce;
	    	objectMesh->AddForce(vecForce);
	    	
	    }
    }
	return vecForce.Z;

 }
