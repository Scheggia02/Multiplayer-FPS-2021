#pragma once

#include "CoreMinimal.h"
#include "Character/Weapon/BaseGun.h"
#include "Firearm.generated.h"


UCLASS()
class MULTIPLAYERFPS_API AFirearm : public ABaseGun
{
	GENERATED_BODY()

public:
	AFirearm() = default;

protected:
	virtual void reload() override;

	UFUNCTION(BlueprintCallable)
	virtual void startFiring() override;
	UFUNCTION(BlueprintCallable)
	virtual void stopFiring() override;

	UFUNCTION(BlueprintCallable)
	virtual void startReloading() override;
	virtual void stopReloading() override {};

	virtual void spawnFireEffects() override {};
	virtual void spawnReloadEffects() override {};

public:
	virtual void fire();
};
