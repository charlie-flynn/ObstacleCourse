// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityCamera.h"
#include "Components/SpotLightComponent.h"
#include "Components/BoxComponent.h"
#include "ObstacleGamePlayerState.h"

// Sets default values
ASecurityCamera::ASecurityCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;
	Camera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Camera"));
	DetectionZone = CreateDefaultSubobject<UBoxComponent>(TEXT("Detection Zone"));
	Spotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Spotlight"));
	Camera->SetupAttachment(RootComponent);										
	DetectionZone->SetupAttachment(RootComponent);										
	Spotlight->SetupAttachment(RootComponent);

	DetectionZone->SetCollisionProfileName("OverlapAll");
	Spotlight->SetLightColor({ 0, 255, 0 });
}

// Called when the game starts or when spawned
void ASecurityCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASecurityCamera::UpdateSpotlightStatus(bool SpottedPlayer)
{
	Spotlight->SetLightColor(SpottedPlayer ? FLinearColor(255, 0, 0) : FLinearColor(0, 255, 0), false);

	// AObstacleGamePlayerState* playerState = get the player state and try to cast it
	// if playerState exists
	// fire UpdatePlayerVisibility
	AObstacleGamePlayerState* PlayerState = GetWorld()->GetFirstPlayerController() != NULL ? GetWorld()->GetFirstPlayerController()->GetPlayerState<AObstacleGamePlayerState>() : NULL;

	if (PlayerState)
		PlayerState->UpdatePlayerVisibilityStatus(SpottedPlayer);
}

