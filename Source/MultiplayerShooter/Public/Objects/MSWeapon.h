// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Objects/MSItem.h"
#include "Data/MSWeaponDataAsset.h"
#include "Core/MSFStructItem.h"
#include "MSWeapon.generated.h"

class UStaticMesh;

UCLASS()
class MULTIPLAYERSHOOTER_API AMSWeapon final : public AMSItem
{
    GENERATED_BODY()

public:
    AMSWeapon();
    virtual void Use() override;
    bool ValidFirstModule() const;
    bool ValidSecondModule() const;

private:
    UPROPERTY()
    UStaticMesh* StaticMeshWeapon;
    EWeaponType WeaponType;
    void OffModule(FModule &FModuleWeapon);
    bool validFirstModule = false;
    bool validSecondModule = false;

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void LoadDefaultSettings() override;
    virtual void Init(bool LoadDefault = false) override;
};
