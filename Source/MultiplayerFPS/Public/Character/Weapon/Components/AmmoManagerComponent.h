// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYERFPS_API UAmmoManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAmmoManagerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	int32 magazineSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	bool shouldMagazineStartFilled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	int32 stockpileSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	bool shouldStockpileStartFilled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Stats")
	int32 ammoFiredPerShot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 currentMagazineAmmo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	int32 currentStockpileAmmo;

protected:
	virtual void BeginPlay() override;

public:	
	bool canFire() const;
	bool canReload() const;

	void shootAmmo();
	void reloadAmmo();
};
