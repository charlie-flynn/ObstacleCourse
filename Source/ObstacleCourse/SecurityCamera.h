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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* DetectionZone;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Camera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpotLightComponent* Spotlight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable)
	void UpdateSpotlightStatus(bool SpottedPlayer);
};
