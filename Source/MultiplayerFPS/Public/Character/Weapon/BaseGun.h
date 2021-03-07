// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Weapon/BaseWeapon.h"
#include "BaseGun.generated.h"

class UAmmoManagerComponent;
class UFiringModeManager;
class UCameraComponent;

UCLASS(Abstract)
class MULTIPLAYERFPS_API ABaseGun : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	ABaseGun();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* playerCameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UFiringModeManager* firingModeManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAmmoManagerComponent* ammoManagerComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float gunRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float baseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float headShotDamageMultiplier;

	FCollisionQueryParams queryParams;
	bool isFiring;

protected:
	virtual void startFiring() {};
	virtual void stopFiring() {};

	virtual void reload() {};
	virtual void startReloading() {};
	virtual void stopReloading() {};

	virtual void spawnFireEffects() {};
	virtual void spawnReloadEffects() {};

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void setupWeapon(AActor* newOwner, UCameraComponent* cameraComp) override;

public:
	virtual void fire() {};

};
