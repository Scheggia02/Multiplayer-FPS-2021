// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class UCameraComponent;

UCLASS(Abstract)
class MULTIPLAYERFPS_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* meshComp;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void setupWeapon(AActor* newOwner, UCameraComponent* cameraComp);
};
