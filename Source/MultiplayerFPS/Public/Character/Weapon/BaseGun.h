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
	virtual void Fire() PURE_VIRTUAL(ABaseGun::Fire, );
	virtual void SpawnFireEffects() PURE_VIRTUAL(ABaseGun::SpawnFireEffects, );
	//virtual void StartFiring() PURE_VIRTUAL(ABaseGun::StartFire, );
	//virtual void StopFiring() PURE_VIRTUAL(ABaseGun::StopFire, );

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void SetupWeapon(AActor* newOwner, UCameraComponent* cameraComp) override;
};
