// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Beat.generated.h"

UCLASS()
class RYTHMGAME_API ABeat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class USphereComponent* GetSphereComp() const { return SphereComp; }

	FORCEINLINE  class UPaperSpriteComponent* GetPaperSpriteComp() const { return PaperSpriteComp; }

	UPROPERTY(EditDefaultsOnly, Category = "Beat Settings")
	float Speed;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Beat, meta=(AllowPrivateAccess = true))
	class USphereComponent* SphereComp;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Beat, meta = (AllowPrivateAccess = true))
	class UPaperSpriteComponent* PaperSpriteComp;
	
};
