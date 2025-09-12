// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueBox.generated.h"

UCLASS()
class OBSTACLECOURSE_API ADialogueBox : public AActor
{
	GENERATED_BODY()
	

private:
	TArray<FString> Dialogue;
	FString DisplayDialogue;
	
	int DialogueTextIndex;

	float CharacterDisplayDelay;
	float CharacterDisplayTimer;

public:
	// Sets default values for this actor's properties
	ADialogueBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddDialogue(FString AddedDialogue);

	UFUNCTION(BlueprintCallable)
	FString GetDisplayDialogue();

	UFUNCTION(BlueprintCallable)
	bool IsDialogueEmpty();

};
