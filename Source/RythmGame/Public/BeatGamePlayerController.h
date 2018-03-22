// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BeatGamePlayerController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChangeSignature, int32, CurrentScore);
/**
 * 
 */
UCLASS()
class RYTHMGAME_API ABeatGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABeatGamePlayerController();

	int32 GetScore();
	void AddScore(int32 Amount);

	UPROPERTY(BlueprintAssignable)
	FOnScoreChangeSignature OnScoreChange;

protected:
	
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;

	class ABeatInputManager* LevelBeatManager;

	void ProcessBeatInput(class ABeatInput* BeatInput);

	void Key1Pressed();

	void Key2Pressed();

	void Key3Pressed();

	void Key4Pressed();

private:
	int32 _score;
	
};
