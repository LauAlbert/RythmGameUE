// Fill out your copyright notice in the Description page of Project Settings.

#include "BeatInput.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ABeatInput::ABeatInput()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;
	


	PaperSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComp"));
	PaperSpriteComp->SetupAttachment(SphereComp);

}

// Called when the game starts or when spawned
void ABeatInput::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeatInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AActor*> ABeatInput::GetSphereCompOverlap()
{
	TArray<AActor*> OverlapActors;
	SphereComp->GetOverlappingActors(OverlapActors);
	return OverlapActors;
}

