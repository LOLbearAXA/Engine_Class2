// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AMainPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ENGINE_CLASS2_API AAMainPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	int GetPlayerScore() const { return PlayerScore; }

	UFUNCTION(BlueprintCallable)
	void AddPlayerScore(int amount);

private:
	UPROPERTY(VisibleAnywhere)
	int PlayerScore = 0; // set to 0 by defalut

};
