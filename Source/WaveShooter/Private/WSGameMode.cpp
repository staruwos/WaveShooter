// Fill out your copyright notice in the Description page of Project Settings.


#include "WSGameMode.h"
#include "UObject/ConstructorHelpers.h"

AWSGameMode::AWSGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerBPPawn(TEXT("/Game/Blueprints/BP_PlayerPawn"));


	if (PlayerBPPawn.Class != NULL)
		DefaultPawnClass = PlayerBPPawn.Class;

}