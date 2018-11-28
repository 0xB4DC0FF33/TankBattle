// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	// LOG(LogTemp, Warning, TEXT("AAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHH"));
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation = %s"), *HitLocation.ToString());
		// TODO : Tank aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLoc) const {
	// Raycast from turret trough crosshair
	// If hit return true & pass hit location in HitLoc
	// Else return false

	HitLoc.Set(42.00, 42.00, 42.00);
	return true;

}