#include "Character/Weapon/Components/AmmoManagerComponent.h"

UAmmoManagerComponent::UAmmoManagerComponent() : magazineSize(0), shouldMagazineStartFilled(false), stockpileSize(0), shouldStockpileStartFilled(false)
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}


void UAmmoManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	currentMagazineAmmo = shouldMagazineStartFilled ? magazineSize : 0;
	currentStockpileAmmo = shouldStockpileStartFilled ? stockpileSize : 0;
}

bool UAmmoManagerComponent::canFire() const
{ 
	return currentMagazineAmmo >= ammoFiredPerShot;
}

bool UAmmoManagerComponent::canReload() const
{ 
	const uint16 missingAmmo = (uint16) (magazineSize - currentMagazineAmmo);

	return currentStockpileAmmo > 0 && missingAmmo > 0;
}

void UAmmoManagerComponent::shootAmmo()
{
	currentMagazineAmmo -= ammoFiredPerShot;
}

void UAmmoManagerComponent::reloadAmmo()
{
	const uint16 missingAmmo = (uint16)(magazineSize - currentMagazineAmmo);
	currentStockpileAmmo -= missingAmmo;
	currentMagazineAmmo = magazineSize;
}
