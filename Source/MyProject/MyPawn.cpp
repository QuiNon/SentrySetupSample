// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "SentrySubsystem.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		UE_LOG(LogTemp, Log, TEXT("GEngine Init"));
		if (USentrySubsystem* Sentry = GEngine->GetEngineSubsystem<USentrySubsystem>())
		{
			Sentry->CaptureMessage(TEXT("Game Init information"), ESentryLevel::Info);
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("GEngine USentrySubsystem not found"));
		}
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Sentry Not started Init"));
	}

	UE_LOG(LogTemp, Log, TEXT("UBaseRosGameInstance::Init"));


	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

