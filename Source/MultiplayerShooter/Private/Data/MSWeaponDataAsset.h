// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/MSBaseDataAsset.h"
#include "Data/MSModuleWeaponDataAsset.h"
#include "Core/MSFStructItem.h"
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

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    EWeaponType WeaponType;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    UStaticMesh* WeaponMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    UMSModuleWeaponDataAsset* FirstModule;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    UMSModuleWeaponDataAsset* SecondModule;

public:
    EWeaponType GetWeaponType() const
    {
        return WeaponType;
    }

    UStaticMesh* GetStaticMesh() const
    {
        return WeaponMesh;
    }

    bool ValidFirstModule() const
    {
        if (FirstModule)
            return true;
        return false;
    }

    bool ValidSecondModule() const
    {
        if (SecondModule)
            return true;
        return false;
    }

    FModule GetFirstModule() const
    {
        if (ValidFirstModule())
            return FirstModule->GetAllSettings();
        return FModule(0, 0, 0, 0);
    }

    FModule GetSecondModule() const
    {
        if (ValidSecondModule())
            return SecondModule->GetAllSettings();
        return FModule(0, 0, 0, 0);
    }
};
