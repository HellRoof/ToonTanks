// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

private:

	bool bIsPlayerAlive = true;
	FVector MoveDirection;
	FQuat RotationDirection;
	APlayerController* PlayerControllerRef{nullptr};

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivatAccess = "true"))
	USpringArmComponent* SpringArm{nullptr};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivatAccess = "true"))
	UCameraComponent* Camera{nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Settings", meta = (AllowPrivatAccess = "true"))
		float MoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Settings", meta = (AllowPrivatAccess = "true"))
		float RotateSpeed = 100.f;
	
public:

	APawnTank();

	virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
