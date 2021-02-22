#include "Character/Weapon/SingleFireGun.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void ASingleFireGun::Fire()
{
	if (playerCameraComp == nullptr || gunRange == 0.0f)//Check if the player's camera or the gunRange is null, if it is, return!
	{
		UE_LOG(LogTemp, Log, TEXT("Can't fire"));
		return;
	}

	FVector startLoc = playerCameraComp->GetComponentLocation(); //Trace's start location
	FVector endLoc = startLoc + (playerCameraComp->GetForwardVector() * gunRange); //Trace's end location

	FHitResult hit;

	bool bHit = GetWorld()->LineTraceSingleByChannel(hit, startLoc, endLoc, ECollisionChannel::ECC_Visibility, queryParams); 

	if (bHit) // if we hit something
	{
		UE_LOG(LogTemp, Log, TEXT("Hit something")); 
	}

	SpawnFireEffects();
	UKismetSystemLibrary::DrawDebugLine(this, startLoc, endLoc, FLinearColor::Blue, 1.5f, 1.0f);

}

void ASingleFireGun::SpawnFireEffects()
{
}

