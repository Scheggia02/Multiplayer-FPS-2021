#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiringModeManager.generated.h"

class ABaseGun;

UENUM(BlueprintType)
enum class EFiringMode : uint8
{
	SINGLE_FIRE,
	AUTOMATIC_FIRE,
	BURST
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYERFPS_API UFiringModeManager : public UActorComponent
{
	GENERATED_BODY()


public:
	UFiringModeManager();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats")
	EFiringMode firingMode;
	
	/*Bullets fired per minute - RPM*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun Stats", meta = (ClampMin = "1"))
	float rateOfFire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gun Stats", meta = (ClampMin = "1", EditCondition = "firingMode==EFiringMode::BURST"))
	int32 firesPerShot;

	float lastFireTime;
	float timeBetweenShots;

	uint8 firedBurstShots;
	class ABaseGun* ownerGun;
	FTimerHandle TH_FiringMode;

protected:
	void fire();

	virtual void BeginPlay() override;

public:	
	void startFiring(ABaseGun* gunRef);
	void stopFiring();
	
	EFiringMode getCurrentFiringMode() const { return firingMode; }
};
