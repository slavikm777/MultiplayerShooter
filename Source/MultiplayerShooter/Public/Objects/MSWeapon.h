// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Objects/MSItem.h"
#include "Data/MSWeaponDataAsset.h"
#include "MSWeapon.generated.h"

class UStaticMesh;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSWeapon : public AMSItem
{
    GENERATED_BODY()

public:
    AMSWeapon();

protected:
    UPROPERTY(EditAnyWhere, Category = "Settings");
    UMSWeaponDataAsset* WeaponDataAsset;

    UPROPERTY()
    UStaticMesh* StaticMeshWeapon;
    EWeaponType WeaponType;
    float Damage;

    virtual void Init() override;
    virtual void OnConstruction(const FTransform& Transform) override;
};
