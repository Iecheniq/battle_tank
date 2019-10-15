// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);
   AimTowardsCrosshairs();
}

ATank* ATankPlayerController::GetControlledTank()const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshairs()
{
    if (!GetControlledTank()){return;}

    FVector HitLocation; // Out parameter
    if(GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
        //Tell controlled tank to aim at this point
    }
}

//Get world location if linetrace through crosshair, true if it hits landscape
bool ATankPlayerController:: GetSightRayHitLocation(FVector& OutHitLocation) const
{
    OutHitLocation = FVector(1.0);
    return true;
}

