// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleGamePlayerState.h"

int AObstacleGamePlayerState::GetCoins()
{
	return Coins;
}

bool AObstacleGamePlayerState::SetCoins(int amount)
{
	Coins = amount;
	return true;
}

bool AObstacleGamePlayerState::GetPlayerVisibility()
{
	return PlayerVisibility;
}

bool AObstacleGamePlayerState::AddCoins(int amount)
{
	SetCoins(Coins + amount);
	OnCoinUpdateDispatcher.Broadcast(Coins, amount);
	return true;
}

bool AObstacleGamePlayerState::UpdatePlayerVisibilityStatus(bool newValue)
{
	// don't do anythang if the new value is the same as the old
	if (PlayerVisibility == newValue) return false;

	PlayerVisibility = newValue;
	OnPlayerVisiblityChangedDispatcher.Broadcast(PlayerVisibility);
	return true;
}
