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
	Camera->SetupAttachment(RootComponent);										
	DetectionZone->SetupAttachment(RootComponent);										
	Spotlight->SetupAttachment(RootComponent);

	DetectionZone->SetCollisionProfileName("OverlapAll");
}

// Called when the game starts or when spawned
void ASecurityCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecurityCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecurityCamera::UpdateSpotlightStatus(bool SpottedPlayer)
{
	Spotlight->SetLightColor(SpottedPlayer ? FLinearColor(0, 255, 0) : FLinearColor(255, 0, 0), false);

	// AObstacleGamePlayerState* playerState = get the player state and try to cast it
	// if playerState exists
	// fire UpdatePlayerVisibility
	AObstacleGamePlayerState* PlayerState = GetWorld()->GetFirstPlayerController() != NULL ? GetWorld()->GetFirstPlayerController()->GetPlayerState<AObstacleGamePlayerState>() : NULL;

	if (PlayerState)
		PlayerState->UpdatePlayerVisibilityStatus(SpottedPlayer);
}

