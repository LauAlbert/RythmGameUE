// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeatInputManager.generated.h"

class ABeatInput;

UCLASS()
class RYTHMGAME_API ABeatInputManager : public AActor
{
	GENERATED_BODY()
	

public:	
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	ABeatInput* BeatInput1;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	ABeatInput* BeatInput2;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	ABeatInput* BeatInput3;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	ABeatInput* BeatInput4;
	
	
};
