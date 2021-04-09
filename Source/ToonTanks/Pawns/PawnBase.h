// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	APawnBase();
	
	virtual void HandleDestruction();
	
protected:

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundBase* DeathSound;
	
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Effects")
		TSubclassOf<UCameraShake> DeathShake;
	
	UPROPERTY(EditAnywhere, Category="Effects")
		UParticleSystem* DeathPatricle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivatAccess = "true"))
		UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivatAccess = "true"))
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivatAccess = "true"))
		UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivatAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	virtual void RotateTurretFunction(FVector LookAtTarget);

	virtual void Fire();

};
