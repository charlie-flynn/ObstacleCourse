// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueBox.h"

// Sets default values
ADialogueBox::ADialogueBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Dialogue = TArray<FString>();
	DisplayDialogue = FString();
	DialogueTextIndex = 0;

	CharacterDisplayDelay = 0.2f;
	CharacterDisplayTimer = 0.0f;
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

	if (DialogueTextIndex == 0)
	{
		DisplayDialogue = FString();
	}

	// if there is no dialogue, return. otherwise, decrement the timer for the next character to appear
	if (Dialogue.IsEmpty()) return;
	CharacterDisplayTimer -= DeltaTime;

	// if the timer has not hit 0, return. otherwise, reset the timer, and display the next character in the dialogue array
	if (CharacterDisplayTimer > 0) return;

	CharacterDisplayTimer = CharacterDisplayDelay;


	DisplayDialogue.AppendChar(Dialogue[0][DialogueTextIndex]);
	DialogueTextIndex++;

	// if the index is greater than the length of the current string, delete the current dialogue from the array and increase the delay before the next dialogue
	if (DialogueTextIndex > Dialogue[0].Len())
	{
		Dialogue.RemoveAt(0);
		CharacterDisplayTimer = 5.0f;
		DialogueTextIndex = 0;
	}
}

// add the dialogue to the dialogue array
void ADialogueBox::AddDialogue(FString AddedDialogue)
{
	Dialogue.Add(AddedDialogue);
}

// gets the display dialogue
FString ADialogueBox::GetDisplayDialogue()
{
	return DisplayDialogue;
}

bool ADialogueBox::IsDialogueEmpty()
{
	return DisplayDialogue.IsEmpty();
}

