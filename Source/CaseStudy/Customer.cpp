// Fill out your copyright notice in the Description page of Project Settings.


#include "Customer.h"
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ACustomer::ACustomer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void ACustomer::Interact()
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Interacted"));
	bLookAtActor = !bLookAtActor;
}

void ACustomer::TurnToActor(AActor* Actor, float DeltaTime)
{
	if (bLookAtActor)
	{
		FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Player->GetActorLocation());
		SetActorRotation(
			UKismetMathLibrary::RInterpTo(GetActorRotation(), 
				FRotator(GetActorRotation().Pitch, TargetRot.Yaw, GetActorRotation().Roll),
				DeltaTime, 5.0f));
	}
}

// Called every frame
void ACustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TurnToActor(Player, DeltaTime);
}

// Called to bind functionality to input
void ACustomer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

