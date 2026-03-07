// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WAVESHOOTER_API AWSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public: 
	AWSGameMode();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave System")
	int32 CurrentWave;



	
};
