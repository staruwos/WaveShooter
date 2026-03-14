// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WSEnemySpawnPod.generated.h"

UCLASS()
class WAVESHOOTER_API AWSEnemySpawnPod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWSEnemySpawnPod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	/* COMPONENTS */

	// Pod Static Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* PodMesh;

	/* SPAWN SETTINGS */
	// The specific enemy class to spawn (Select this in the Blueprint editor!)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<class ACharacter> EnemyClassToSpawn;

	// Minimum time (in seconds) between spawns
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MinSpawnDelay;

	// Maximum time (in seconds) between spawns
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MaxSpawnDelay;

	// Should this pod start spawning as soon as the game begins?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	bool bAutoStartSpawning;

	/* SPAWN LOGIC */

	// Call this to turn the pod on
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void StartSpawning();

	// Call this to turn the pod off
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void StopSpawning();

protected:
	// Time Handler
	FTimerHandle SpawnTimerHandle;

	// Spawn Enemy Function
	void SpawnEnemy();

};
