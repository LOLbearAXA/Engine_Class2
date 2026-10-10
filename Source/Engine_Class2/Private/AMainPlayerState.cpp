// Fill out your copyright notice in the Description page of Project Settings.


#include "AMainPlayerState.h"
#include "Net/UnrealNetwork.h"

void AAMainPlayerState::AddPlayerScore(int amount)
{
	PlayerScore += amount;
}
