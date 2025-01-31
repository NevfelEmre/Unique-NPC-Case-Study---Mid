// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Interactable.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

bool APlayerCharacter::MakeInteraction(USceneComponent* Camera)
{
	FHitResult Hit;
	const float LineTraceRange = 1000.0f;
	const FVector Start = Camera->GetComponentLocation();
	const FVector End = (Camera->GetForwardVector() * LineTraceRange) + Camera->GetComponentLocation();
	const bool hitSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility);
	/*DrawDebugLine(
		GetWorld(),
		Start,
		End,
		FColor(255, 0, 0),
		false, 5, 0, 0.5f);*/
	if (hitSuccess) {
		IInteractable* InteractActor = Cast<IInteractable>(Hit.GetActor());
		if (InteractActor) {
			InteractActor->Interact();
			return 1;
		}
	}
	return 0;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

