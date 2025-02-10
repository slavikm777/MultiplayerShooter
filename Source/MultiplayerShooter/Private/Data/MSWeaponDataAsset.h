// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/MSBaseDataAsset.h"
#include "MSWeaponDataAsset.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    Rifle = 0,
    Pistol,
    Shotgun,
    Sniper
};

UCLASS()
class UMSWeaponDataAsset : public UMSBaseDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    EWeaponType WeaponType;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    UStaticMesh* WeaponMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    float Damage;
};
