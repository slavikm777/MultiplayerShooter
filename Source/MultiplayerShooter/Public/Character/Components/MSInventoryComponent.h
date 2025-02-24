// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/MSBaseComponent.h"
#include "Core/MSFStructItem.h"
#include "Character/Interfaces/MSInventoryInterface.h"
#include "MSInventoryComponent.generated.h"

class UMSBaseDataAsset;
class IMSEquipmentInterface;

UCLASS()
class MULTIPLAYERSHOOTER_API UMSInventoryComponent : public UMSBaseComponent, public IMSInventoryInterface
{
    GENERATED_BODY()

private:
    UPROPERTY(EditAnywhere, Category = "Settings")
    int MaxSizeInventory = 10;

    UPROPERTY(EditAnywhere, Category = "Settings")
    TArray<FStructItemSlot> ItemSlots;

    int ItemHasInventory(UMSBaseDataAsset* InItem);
    IMSEquipmentInterface* EquipmentInterface;
    int CurrentIndex = 0;
    bool EquipItem(UMSBaseDataAsset* InItem);

protected:
    virtual void BeginPlay() override;

public:
    virtual void UpdateItem(FItem InItem) override;
    bool AddToInventory(FItem InItem);
    void SwitchWeapon(bool NextWeapon);
};
