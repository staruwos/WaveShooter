// Fill out your copyright notice in the Description page of Project Settings.


#include "WSEnemySpawnPod.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AWSEnemySpawnPod::AWSEnemySpawnPod()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create the mesh component and set it as the root
	PodMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PodMesh"));
	RootComponent = PodMesh;

	// Set default values so they aren't totally empty in Blueprint
	MinSpawnDelay = 2.0f;
	MaxSpawnDelay = 5.0f;
	bAutoStartSpawning = false; // Let the GameMode control when it starts!
}

// Called when the game starts or when spawned
void AWSEnemySpawnPod::BeginPlay()
{
	Super::BeginPlay();

	if (bAutoStartSpawning)
	{
		StartSpawning();
	}
	
}

// Called every frame
void AWSEnemySpawnPod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWSEnemySpawnPod::StartSpawning()
{
	// Make sure we have an enemy class selected in the editor before we try to spawn one!
	if (EnemyClassToSpawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Pod %s has no EnemyClassToSpawn assigned!"), *GetName());
		return;
	}

	// Calculate a random delay between our min and max
	float RandomDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);

	// Tell the World's Timer Manager to call our SpawnEnemy function after 'RandomDelay' seconds
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AWSEnemySpawnPod::SpawnEnemy, RandomDelay, false);
}

void AWSEnemySpawnPod::StopSpawning()
{
	// Clear the timer so it stops counting down
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}

void AWSEnemySpawnPod::SpawnEnemy()
{
	if (EnemyClassToSpawn)
	{
		// Figure out where to spawn the enemy (slightly above the pod so they don't get stuck in the floor)
		FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 0.0f, 100.0f);
		FRotator SpawnRotation = GetActorRotation();

		// Spawn parameters to handle collisions
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// Actually spawn the enemy!
		ACharacter* SpawnedEnemy = GetWorld()->SpawnActor<ACharacter>(EnemyClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

		// Once the enemy is spawned, immediately restart the timer to queue up the next one
		StartSpawning();
	}
}

