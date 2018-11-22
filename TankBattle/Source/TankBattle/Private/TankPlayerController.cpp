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

	 // LOG(LogTemp, Warning, TEXT("AAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHH"));

 }

 void ATankPlayerController::AimTowardsCrosshair() {
	 if (!GetControlledTank()) { return; }
	
	 // Raycast trough the crosshair
	 // If hits the landscape 
	 //Tank aim at this point
 
 }
