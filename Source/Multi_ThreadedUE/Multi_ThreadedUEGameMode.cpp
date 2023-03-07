// Copyright Epic Games, Inc. All Rights Reserved.

#include "Multi_ThreadedUEGameMode.h"
#include "Multi_ThreadedUECharacter.h"
#include "UObject/ConstructorHelpers.h"

AMulti_ThreadedUEGameMode::AMulti_ThreadedUEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
