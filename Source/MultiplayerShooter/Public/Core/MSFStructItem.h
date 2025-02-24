// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/MSBaseDataAsset.h"
#include "MSFStructItem.generated.h"

USTRUCT(BlueprintType)
struct FModule
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModuleSettings")
    int Ammo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModuleSettings")
    int TotalAmmo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModuleSettings")
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ModuleSettings")
    float RateOfFire;
};

USTRUCT(BlueprintType)
struct FItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemSlot")
    UMSBaseDataAsset* DataAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemSlot")
    FModule FirstModule;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemSlot")
    FModule SecondModule;
};

USTRUCT(BlueprintType)
struct FStructItemSlot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemSlot")
    bool SelectedItem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemSlot")
    FItem ItemData;
};
