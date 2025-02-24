// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Character/Components/MSInventoryComponent.h"
#include "Data/MSBaseDataAsset.h"
#include "Character/Interfaces/MSEquipmentInterface.h"
#include "Core/Helpers/MSHelperFunctions.h"
#include "Data/MSWeaponDataAsset.h"

void UMSInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    EquipmentInterface = MSHelperFunctions::GetComponentByInterface<IMSEquipmentInterface>(GetOwner());
    check(EquipmentInterface);
}

int UMSInventoryComponent::ItemHasInventory(UMSBaseDataAsset* InItem)
{
    int i = 0;
    for (FStructItemSlot Slot : ItemSlots)
    {
        if (Slot.ItemData.DataAsset == InItem)
            return i;
        i++;
    }
    return -1;
}

bool UMSInventoryComponent::EquipItem(UMSBaseDataAsset* InItem)
{
    for (FStructItemSlot& ItItem : ItemSlots)
    {
        if (ItItem.ItemData.DataAsset == InItem)
        {
            for (FStructItemSlot& ItItem2 : ItemSlots)
                ItItem2.SelectedItem = false;
            ItItem.SelectedItem = true;
            EquipmentInterface->SelectItem(ItItem.ItemData);
            return true;
        }
    }
    return false;
}

void UMSInventoryComponent::UpdateItem(FItem InItem)
{
    int ItemIndex = ItemHasInventory(InItem.DataAsset);
    if (ItemIndex != -1)
        ItemSlots[ItemIndex].ItemData = InItem;
}

bool UMSInventoryComponent::AddToInventory(FItem InItem)
{
    if (!InItem.DataAsset || ItemSlots.Num() >= MaxSizeInventory)
        return false;
    int ItemIndex = ItemHasInventory(InItem.DataAsset);
    if (ItemIndex != -1)
    {
        UMSWeaponDataAsset* WeaponData = Cast<UMSWeaponDataAsset>(ItemSlots[ItemIndex].ItemData.DataAsset);
        // Логика для добавления патронов
        if (ItemSlots[ItemIndex].SelectedItem)
        {
            if (WeaponData->ValidFirstModule())
                ItemSlots[ItemIndex].ItemData.FirstModule.Ammo = InItem.FirstModule.Ammo + EquipmentInterface->GetCurrentItem().FirstModule.Ammo;
            if (WeaponData->ValidSecondModule())
                ItemSlots[ItemIndex].ItemData.SecondModule.Ammo = InItem.SecondModule.Ammo + EquipmentInterface->GetCurrentItem().SecondModule.Ammo;
            EquipmentInterface->SelectItem(ItemSlots[ItemIndex].ItemData, false);
        }
        else
        {
            if (WeaponData->ValidFirstModule())
                ItemSlots[ItemIndex].ItemData.FirstModule.Ammo += InItem.FirstModule.Ammo;
            if (WeaponData->ValidSecondModule())
                ItemSlots[ItemIndex].ItemData.SecondModule.Ammo += InItem.SecondModule.Ammo;
        }
        return true;
    }
    else
    {
        ItemSlots.Add(FStructItemSlot(false, InItem));
    }

    if (ItemSlots.Num() == 1)
        EquipItem(InItem.DataAsset); // Экипировка при условии если нет никакого оружия

    return true;
}

void UMSInventoryComponent::SwitchWeapon(bool NextWeapon)
{
    if (ItemSlots.Num() > 0)
    {
        if (NextWeapon)
        {
            if (CurrentIndex < ItemSlots.Num() - 1)
            {
                CurrentIndex++;
                EquipItem(ItemSlots[CurrentIndex].ItemData.DataAsset);
            }
            else
            {
                CurrentIndex = 0;
                EquipItem(ItemSlots[CurrentIndex].ItemData.DataAsset);
            }
        }
        else
        {
            if (CurrentIndex > 0)
            {
                CurrentIndex--;
                EquipItem(ItemSlots[CurrentIndex].ItemData.DataAsset);
            }
            else
            {
                CurrentIndex = ItemSlots.Num() - 1;
                EquipItem(ItemSlots[CurrentIndex].ItemData.DataAsset);
            }
        }
    }
}
