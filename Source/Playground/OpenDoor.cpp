// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	Owner = GetOwner();
}

void UOpenDoor::OpenDoor()
{
	///sets rotation of door
	Owner->SetActorRotation(FRotator(0.0f, openAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	///sets rotation of door
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpen = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpen > DoorCloseDelay)
	{
		CloseDoor();
	}
}

