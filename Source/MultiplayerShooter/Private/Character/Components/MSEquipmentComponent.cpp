// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Character/Components/MSEquipmentComponent.h"
#include "Components/SceneComponent.h"
#include "Objects/MSItem.h"
#include "Objects/MSWeapon.h"
#include "Character/Interfaces/MSInventoryInterface.h"
#include "Core/Helpers/MSHelperFunctions.h"

void UMSEquipmentComponent::BeginPlay()
{
    Super::BeginPlay();
    InventoryInterface = MSHelperFunctions::GetComponentByInterface<IMSInventoryInterface>(GetOwner());
    check(InventoryInterface);
}

void UMSEquipmentComponent::SetPointAttach(USceneComponent* InScenePointAttach)
{
    check(InScenePointAttach);
    ScenePointAttach = InScenePointAttach;
}

void UMSEquipmentComponent::SelectItem(FItem& InItem, bool Respawn)
{
    if (InItem.DataAsset)
    {
        if(!CurrentItem)
            SpawnItem(InItem);
        else if(CurrentItem && Respawn)
        {
            InventoryInterface->UpdateItem(CurrentItem->GetItemData());
            CurrentItem->Destroy();
            CurrentItem = nullptr;
            SpawnItem(InItem);
        }
        else if(CurrentItem && Respawn == false)
        {
            CurrentItem->InitializeData(InItem);
            return;
        }
    }
}

FItem UMSEquipmentComponent::GetCurrentItem() const
{
    return CurrentItem->GetItemData();
}

void UMSEquipmentComponent::SpawnItem(FItem& InItem)
{
    UWorld* World = GetWorld();
    if (World)
    {
        CurrentItem = World->SpawnActorDeferred<AMSItem>(ItemClass, ScenePointAttach->GetComponentTransform(),
                                                         GetOwner(), GetOwner()->GetInstigator(),
                                                         ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
        if (CurrentItem)
        {
            CurrentItem->InitializeData(InItem);
            CurrentItem->FinishSpawning(ScenePointAttach->GetComponentTransform());
            CurrentItem->AttachToComponent(ScenePointAttach, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
        }
    }
}

void UMSEquipmentComponent::FirstAction()
{
    if (CurrentItem)
        CurrentItem->Use();
}
