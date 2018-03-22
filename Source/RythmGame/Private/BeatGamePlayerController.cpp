// Fill out your copyright notice in the Description page of Project Settings.

#include "BeatGamePlayerController.h"
#include "BeatInputManager.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "BeatInput.h"
#include "Beat.h"

ABeatGamePlayerController::ABeatGamePlayerController()
{
	_score = 0;
}

int32 ABeatGamePlayerController::GetScore()
{
	return _score;
}

void ABeatGamePlayerController::AddScore(int32 Amount)
{
	_score += Amount;
	OnScoreChange.Broadcast(_score);
}

void ABeatGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	OnScoreChange.Broadcast(_score);

	TArray<AActor*> BeatManagers;
	if (GetWorld() != NULL)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABeatInputManager::StaticClass(), BeatManagers);

		if (BeatManagers.Num() > 0)
		{
			ABeatInputManager* BeatManager = Cast<ABeatInputManager>(BeatManagers[0]);
			if (BeatManager != NULL)
			{
				LevelBeatManager = BeatManager;
			}
		}
	}

}



void ABeatGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("key1", IE_Pressed, this, &ABeatGamePlayerController::Key1Pressed);

	InputComponent->BindAction("key2", IE_Pressed, this, &ABeatGamePlayerController::Key2Pressed);

	InputComponent->BindAction("key3", IE_Pressed, this, &ABeatGamePlayerController::Key3Pressed);

	InputComponent->BindAction("key4", IE_Pressed, this, &ABeatGamePlayerController::Key4Pressed);

}

void ABeatGamePlayerController::ProcessBeatInput(ABeatInput* BeatInput)
{
	TArray<AActor*> OverlapActors = BeatInput->GetSphereCompOverlap();
	int32 numberofSuccess = 0;
	for (auto OverlapActor : OverlapActors)
	{
		ABeat* Beat = Cast<ABeat>(OverlapActor);
		if (Beat)
		{
			Beat->Destroy();
			AddScore(10);
			numberofSuccess++;
		}
	}
	if (numberofSuccess == 0)
	{
		AddScore(-10);
	}
}

void ABeatGamePlayerController::Key1Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Key1"));
	if (LevelBeatManager)
	{
		ABeatInput* BeatInput = LevelBeatManager->BeatInput1;
		if (BeatInput)
		{
			ProcessBeatInput(BeatInput);
		}
	}
}

void ABeatGamePlayerController::Key2Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Key2"));
	if (LevelBeatManager)
	{
		ABeatInput* BeatInput = LevelBeatManager->BeatInput2;
		if (BeatInput)
		{
			ProcessBeatInput(BeatInput);
		}
	}
}

void ABeatGamePlayerController::Key3Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Key3"));
	if (LevelBeatManager)
	{
		ABeatInput* BeatInput = LevelBeatManager->BeatInput3;
		if (BeatInput)
		{
			ProcessBeatInput(BeatInput);
		}
	}
}

void ABeatGamePlayerController::Key4Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Key4"));
	if (LevelBeatManager)
	{
		ABeatInput* BeatInput = LevelBeatManager->BeatInput4;
		if (BeatInput)
		{
			ProcessBeatInput(BeatInput);
		}
	}
}