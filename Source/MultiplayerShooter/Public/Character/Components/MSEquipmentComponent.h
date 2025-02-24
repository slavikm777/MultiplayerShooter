// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/MSBaseComponent.h"
#include "Character/Interfaces/MSEquipmentInterface.h"
#include "MSEquipmentComponent.generated.h"

class AMSItem;
class USceneComponent;
class IMSInventoryInterface;

UCLASS()
class MULTIPLAYERSHOOTER_API UMSEquipmentComponent final : public UMSBaseComponent, public IMSEquipmentInterface
{
    GENERATED_BODY()

public:
    void SetPointAttach(USceneComponent* InScenePointAttach);
    void FirstAction();

private:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSubclassOf<AMSItem> ItemClass;
    UPROPERTY()
    USceneComponent* ScenePointAttach;
    AMSItem* CurrentItem;
    IMSInventoryInterface* InventoryInterface;
    virtual void SelectItem(FItem& InItem, bool Respawn = true) override;
    virtual FItem GetCurrentItem() const override;
    void SpawnItem(FItem& InItem);

protected:
    virtual void BeginPlay() override;
};
