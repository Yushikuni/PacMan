// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"
#include "Food.h"

// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverLapBegin);
}

// Called every frame
void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Frozen)
	{
		AddMovementInput(GetActorForwardVector());//aktor pujde tam, kam se kouka

	}

}

// Called to bind functionality to input
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector)
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if (Direction == FVector::DownVector)
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	if (Direction == FVector::RightVector)
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	if (Direction == FVector::LeftVector)
	{
		SetActorRotation(FRotator(0, 180, 180));
	}
}

void APacmanPawn::OnOverLapBegin(AActor* PlayerActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Food.Regular"))
	{
		Cast<AFood>(OtherActor)->Consume();
	}
	else if (OtherActor->ActorHasTag("Food.PowerUp"))
	{
		Cast<AFood>(OtherActor)->Consume();
	}
}

