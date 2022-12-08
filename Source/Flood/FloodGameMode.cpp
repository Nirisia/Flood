// Copyright Epic Games, Inc. All Rights Reserved.

#include "FloodGameMode.h"
#include "FloodCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFloodGameMode::AFloodGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
