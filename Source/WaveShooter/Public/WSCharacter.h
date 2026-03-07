// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "WSCharacter.generated.h"

UCLASS()
class WAVESHOOTER_API AWSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/* Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/* Other Properties */

	/* Aiming */
	// Is the player currently holding the aim button?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	bool bIsAiming;

	// Normal Field of View
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float DefaultFOV;

	// Zoomed-in Field of View
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float AimFOV;

	// How fast the camera transitions between default and aim FOV
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float ZoomInterpSpeed;

	/* Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	// Aim Input Action (Button)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AimAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	// Aiming functions
	void StartAiming();
	void StopAiming();

};
