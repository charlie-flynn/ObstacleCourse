// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ObstacleGamePlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCoinUpdateDispatcher, float, NewCoins, float, NewCoinAmount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerVisibilityChanged, bool, NewPlayerVisibility);

UCLASS()
class OBSTACLECOURSE_API AObstacleGamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	int Coins = 0;
	bool PlayerVisibility = false;

public:
	int GetCoins();
	bool SetCoins(int amount);

	bool GetPlayerVisibility();

	UFUNCTION(BlueprintCallable)
	bool AddCoins(int amount);

	UPROPERTY(BlueprintAssignable)
	FOnCoinUpdateDispatcher OnCoinUpdateDispatcher;
	
	bool UpdatePlayerVisibilityStatus(bool newValue);
	
	UPROPERTY(BlueprintAssignable)
	FOnPlayerVisibilityChanged OnPlayerVisiblityChangedDispatcher;

};
