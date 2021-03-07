#include "Character/Weapon/Firearm.h"
#include "Camera/CameraComponent.h"
#include "Character/Weapon/Components/AmmoManagerComponent.h"
#include "Character/Weapon/Components/FiringModeManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Character/PlayerCharacter.h"

void AFirearm::fire()
{
	if (playerCameraComp == nullptr || gunRange == 0.0f || !ammoManagerComp->canFire()) //Check if the stats are valid, otherwise return!
	{
		stopFiring();
		return;
	}

	FVector startLoc = playerCameraComp->GetComponentLocation(); //Trace's start location
	FVector endLoc = startLoc + (playerCameraComp->GetForwardVector() * gunRange); //Trace's end location

	FHitResult hit;
	bool hitSomething = GetWorld()->LineTraceSingleByChannel(hit, startLoc, endLoc, ECollisionChannel::ECC_Visibility, queryParams);

	if (hitSomething) // if we hit something
	{
		UE_LOG(LogTemp, Log, TEXT("Hit something")); 

		APlayerCharacter* hitChar = Cast<APlayerCharacter>(hit.Actor);
		if (hitChar)
		{
			hitChar->takeHit(this, baseDamage);
		}
	}

	ammoManagerComp->shootAmmo();

	spawnFireEffects();
	UKismetSystemLibrary::DrawDebugLine(this, startLoc, endLoc, FLinearColor::Blue, 1.5f, 1.0f);
}

void AFirearm::reload()
{
	ammoManagerComp->reloadAmmo();
}

void AFirearm::startFiring()
{
	firingModeManager->startFiring(this);
	isFiring = true;
}

void AFirearm::stopFiring()
{
	if ( ! isFiring || firingModeManager->getCurrentFiringMode() != EFiringMode::AUTOMATIC_FIRE)//Check if the stats are valid, otherwise return!
	{
		UE_LOG(LogTemp, Log, TEXT("CAN'T STOP FIRING, YOU MUST BE FIRING"));
		return;
	}

	firingModeManager->stopFiring();
	isFiring = false;
}


void AFirearm::startReloading()
{
	if (playerCameraComp == nullptr || gunRange == 0.0f || !ammoManagerComp->canReload()) //Check if the stats are valid, otherwise return!
	{
		UE_LOG(LogTemp, Log, TEXT("CAN'T RELOAD"));
		return;
	}

	reload();
}