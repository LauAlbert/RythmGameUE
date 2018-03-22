// Fill out your copyright notice in the Description page of Project Settings.

#include "Beat.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ABeat::ABeat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;

	PaperSpriteComp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteComp"));
	PaperSpriteComp->SetupAttachment(SphereComp);

	Speed = 10.0f;
}

// Called when the game starts or when spawned
void ABeat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float NewLocation = DeltaTime * Speed;
	SetActorLocation(GetActorLocation() - FVector(NewLocation, 0.0f, 0.0f));

}

