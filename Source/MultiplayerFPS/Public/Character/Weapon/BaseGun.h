// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Weapon/BaseWeapon.h"
#include "BaseGun.generated.h"

class UAmmoManagerComponent;
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
	UAmmoManagerComponent* ammoManagerComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float gunRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float baseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	float headShotDamageMultiplier;

	FCollisionQueryParams queryParams;

protected:
	virtual void fire(bool& hitSomething, FHitResult& hitResult) PURE_VIRTUAL(ABaseGun::fire, );
	virtual void reload() PURE_VIRTUAL(ABaseGun::reload, );

	virtual void spawnFireEffects() PURE_VIRTUAL(ABaseGun::spawnFireEffects, );
	virtual void spawnReloadEffects() PURE_VIRTUAL(ABaseGun::spawnReloadEffects, );

	//virtual void StartFiring() PURE_VIRTUAL(ABaseGun::StartFire, );
	//virtual void StopFiring() PURE_VIRTUAL(ABaseGun::StopFire, );

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void setupWeapon(AActor* newOwner, UCameraComponent* cameraComp) override;
};
