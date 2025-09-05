// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecurityCamera.generated.h"

class USpotLightComponent;
class UBoxComponent;

UCLASS()
class OBSTACLECOURSE_API ASecurityCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecurityCamera();

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* RootScene;

	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* DetectionZone;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Camera;

	UPROPERTY(BlueprintReadWrite)
	USpotLightComponent* Spotlight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION(BlueprintCallable)
	void UpdateSpotlightStatus(bool SpottedPlayer);
};
