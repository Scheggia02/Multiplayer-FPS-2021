#pragma once

#include "CoreMinimal.h"
#include "Character/Weapon/BaseGun.h"
#include "SingleFireGun.generated.h"


UCLASS()
class MULTIPLAYERFPS_API ASingleFireGun : public ABaseGun
{
	GENERATED_BODY()

public:
	ASingleFireGun() = default;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void fire(bool& hitSomething, FHitResult& hitResult) override;

	UFUNCTION(BlueprintCallable)
	virtual void reload() override;

	virtual void spawnFireEffects() override;
	virtual void spawnReloadEffects() override;
};
