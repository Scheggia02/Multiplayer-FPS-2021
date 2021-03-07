#include "Character/Weapon/Components/FiringModeManager.h"
#include "Character/Weapon/BaseGun.h"
#include "TimerManager.h"

UFiringModeManager::UFiringModeManager() : firingMode(EFiringMode::SINGLE_FIRE), rateOfFire(100.0f), firesPerShot(1), lastFireTime(0.0f), timeBetweenShots(0.0f),
										   firedBurstShots(0)
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UFiringModeManager::fire()
{
	if (ownerGun == nullptr)
	{
		stopFiring();
	}

	ownerGun->fire();
	lastFireTime = GetWorld()->TimeSeconds;

	if (firingMode == EFiringMode::BURST)
	{
		firedBurstShots++;

		if (firedBurstShots == firesPerShot)
		{
			stopFiring();
		}
	}
	else if (firingMode == EFiringMode::SINGLE_FIRE)
	{
		stopFiring();
	}
}

void UFiringModeManager::startFiring(ABaseGun* gunRef)
{
	ownerGun = gunRef;
	
	float firstDelay = FMath::Max(lastFireTime + timeBetweenShots - GetWorld()->TimeSeconds, 0.0f);
	GetWorld()->GetTimerManager().SetTimer(TH_FiringMode, this, &UFiringModeManager::fire, timeBetweenShots, true, firstDelay);
}

void UFiringModeManager::stopFiring()
{
	firedBurstShots = 0;
	GetWorld()->GetTimerManager().PauseTimer(TH_FiringMode);
}

void UFiringModeManager::BeginPlay()
{
	Super::BeginPlay();

	timeBetweenShots = 60 / rateOfFire;
}