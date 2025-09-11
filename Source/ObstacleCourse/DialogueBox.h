// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueBox.generated.h"

UCLASS()
class OBSTACLECOURSE_API ADialogueBox : public AActor
{
	GENERATED_BODY()
	


public:	
	UPROPERTY(BlueprintReadWrite)
	TArray<FText> Dialogue;

private:
	FString* DisplayDialogue;
	
public:
	// Sets default values for this actor's properties
	ADialogueBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
