#include "Character/Weapon/BaseGun.h"
#include "Character/Weapon/Components/AmmoManagerComponent.h"
#include "Camera/CameraComponent.h"

ABaseGun::ABaseGun() : gunRange(1.0f), baseDamage(0.0f), headShotDamageMultiplier(1.0f)
{
	ammoManagerComp = CreateDefaultSubobject<UAmmoManagerComponent>(TEXT("AmmoManagerComponent"));
	AddOwnedComponent(ammoManagerComp);

	queryParams.bTraceComplex = true;
	queryParams.AddIgnoredActor(this);
}

void ABaseGun::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseGun::SetupWeapon(AActor* owner, UCameraComponent* cameraComp)
{
	playerCameraComp = cameraComp;
	SetOwner(owner);
	queryParams.AddIgnoredActor(owner);
}
