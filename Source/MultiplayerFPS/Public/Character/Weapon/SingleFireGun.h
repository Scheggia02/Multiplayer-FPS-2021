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
	virtual void Fire() override;
	virtual void SpawnFireEffects() override;
};
