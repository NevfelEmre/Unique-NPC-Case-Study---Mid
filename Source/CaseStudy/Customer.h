// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

UCLASS()
class CASESTUDY_API ACustomer : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Interact() override;

	UFUNCTION()
	void TurnToActor(AActor* Actor,float DeltaTime);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bLookAtActor = 0;
	UPROPERTY()
	AActor* Player = nullptr;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
