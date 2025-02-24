// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/MSBaseDataAsset.h"
#include "Core/MSFStructItem.h"
#include "MSModuleWeaponDataAsset.generated.h"

UCLASS()
class UMSModuleWeaponDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FModule Settings;
    
public:
    /*float GetDamage() const { return Settings.Damage; }
    int GetTotalAmmo() const { return Settings.TotalAmmo; }
    int GetAmmo() const { return Settings.Ammo; }
    float GetRateOfFire() const { return Settings.RateOfFire; }*/
    FModule GetAllSettings() const { return Settings; }
};
