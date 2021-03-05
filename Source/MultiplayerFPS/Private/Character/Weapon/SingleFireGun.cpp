#include "Character/Weapon/SingleFireGun.h"
#include "Camera/CameraComponent.h"
#include "Character/Weapon/Components/AmmoManagerComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void ASingleFireGun::fire(bool& hitSomething, FHitResult& hitResult)
{
	if (playerCameraComp == nullptr || gunRange == 0.0f || !ammoManagerComp->canFire()) //Check if the stats are valid, otherwise return!
	{
		UE_LOG(LogTemp, Log, TEXT("CAN'T FIRE"));
		return;
	}

	FVector startLoc = playerCameraComp->GetComponentLocation(); //Trace's start location
	FVector endLoc = startLoc + (playerCameraComp->GetForwardVector() * gunRange); //Trace's end location

	FHitResult hit;
	hitSomething = GetWorld()->LineTraceSingleByChannel(hit, startLoc, endLoc, ECollisionChannel::ECC_Visibility, queryParams);

	if (hitSomething) // if we hit something
	{
		UE_LOG(LogTemp, Log, TEXT("Hit something")); 
		hitResult = hit;
	}

	ammoManagerComp->shootAmmo();

	spawnFireEffects();
	UKismetSystemLibrary::DrawDebugLine(this, startLoc, endLoc, FLinearColor::Blue, 1.5f, 1.0f);

}

void ASingleFireGun::reload()
{
	if (playerCameraComp == nullptr || gunRange == 0.0f || !ammoManagerComp->canReload()) //Check if the stats are valid, otherwise return!
	{
		UE_LOG(LogTemp, Log, TEXT("CAN'T RELOAD"));
		return;
	}

	ammoManagerComp->reloadAmmo();

}

void ASingleFireGun::spawnFireEffects()
{
}

void ASingleFireGun::spawnReloadEffects()
{
}

