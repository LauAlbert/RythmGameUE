// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeatInput.generated.h"

UCLASS()
class RYTHMGAME_API ABeatInput : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeatInput();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UPaperSpriteComponent* GetSprite() const { return PaperSpriteComp; }

	FORCEINLINE class USphereComponent* GetSphereComp() const { return SphereComp; }

	UFUNCTION(BlueprintCallable, Category = Beat)
	TArray<AActor*> GetSphereCompOverlap();
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Beat, meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* PaperSpriteComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Beat, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComp;
};
