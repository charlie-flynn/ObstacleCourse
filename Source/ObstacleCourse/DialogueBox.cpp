// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueBox.h"

// Sets default values
ADialogueBox::ADialogueBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Dialogue = TArray<FText>();
	DisplayDialogue = new FString();
}

// Called when the game starts or when spawned
void ADialogueBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADialogueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

