// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreChanged);

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	int32 GetTurgetTurretCount();
	APlayerControllerBase *PlayerControllerRef;
	
	APawnTank *PlayerTank;


	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

public:

	void ActorDied(AActor* DeadActor);

protected:

	UPROPERTY(BlueprintAssignable)
	FOnScoreChanged OnScoreChanged;
	
	UFUNCTION(BlueprintCallable, Category= "My Function")
	void CalculateScore();
	
	UPROPERTY(BlueprintReadOnly, Category="Game Statistics")
	int32 PlayerScore{ 0 };
	
	UPROPERTY(BlueprintReadOnly, Category="Game Statistics")
	int32 TargetTurret{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay{3};

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};
