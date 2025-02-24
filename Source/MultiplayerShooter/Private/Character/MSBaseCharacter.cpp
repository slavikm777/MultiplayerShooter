// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Character/MSBaseCharacter.h"
#include "Character/Components/MSInventoryComponent.h"
#include "Character/Components/MSEquipmentComponent.h"
#include "Components/SceneComponent.h"

AMSBaseCharacter::AMSBaseCharacter()
{
    InventoryComponent = CreateDefaultSubobject<UMSInventoryComponent>(TEXT("InventoryComponent"));
    check(InventoryComponent);
    EquipmentComponent = CreateDefaultSubobject<UMSEquipmentComponent>(TEXT("EquipmentComponent"));
    check(EquipmentComponent);
    SceneComponentPointAttach = CreateDefaultSubobject<USceneComponent>(TEXT("PointWeaponAttach"));
    check(SceneComponentPointAttach);
    SceneComponentPointAttach->SetupAttachment(RootComponent);
    EquipmentComponent->SetPointAttach(SceneComponentPointAttach);
}

bool AMSBaseCharacter::PickUp(FItem InItem)
{
    UE_LOG(LogTemp, Warning, TEXT("Ok in Character"));
    return InventoryComponent->AddToInventory(InItem);
}
