// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:

	FTimerHandle FireRateTimerHandle;

	APawnTank* PlayerPawn{nullptr};

	void CheckFireCondition();

	float ReturnDistanceToPlayer();
	
public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate{ 2.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRange{500.f};
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
