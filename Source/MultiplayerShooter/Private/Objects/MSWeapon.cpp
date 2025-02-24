// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Objects/MSWeapon.h"
#include "Core/MSFStructItem.h"

AMSWeapon::AMSWeapon()
{
    Init();
}

void AMSWeapon::Use()
{
    ItemData.FirstModule.Ammo--;
    UE_LOG(LogTemp, Warning, TEXT("Ammo = %d"), ItemData.FirstModule.Ammo);
}

bool AMSWeapon::ValidFirstModule() const
{
    return validFirstModule;
}

bool AMSWeapon::ValidSecondModule() const
{
    return validSecondModule;
}

void AMSWeapon::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    Init();
}

void AMSWeapon::LoadDefaultSettings()
{
    Init(true);
}

void AMSWeapon::OffModule(FModule &FModuleWeapon)
{
    FModuleWeapon.Ammo = 0;
    FModuleWeapon.Damage = 0.0f;
    FModuleWeapon.RateOfFire = 0.0f;
    FModuleWeapon.TotalAmmo = 0;
}

void AMSWeapon::Init(bool LoadDefault)
{
    UMSWeaponDataAsset* WeaponDataAsset = Cast<UMSWeaponDataAsset>(ItemData.DataAsset);
    if (WeaponDataAsset)
    {
        StaticMeshWeapon = WeaponDataAsset->GetStaticMesh();
        WeaponType = WeaponDataAsset->GetWeaponType();
        validFirstModule = WeaponDataAsset->ValidFirstModule();
        validSecondModule = WeaponDataAsset->ValidSecondModule();
        if(!validFirstModule)
            OffModule(ItemData.FirstModule);
        if (!validSecondModule)
            OffModule(ItemData.SecondModule);
        if (LoadDefault)
        {
            ItemData.FirstModule = WeaponDataAsset->GetFirstModule();
            ItemData.SecondModule = WeaponDataAsset->GetSecondModule();
        }
    }
    else
    {
        StaticMeshWeapon = nullptr;
        WeaponType = EWeaponType::Rifle;
    }
    StaticMeshComponent->SetStaticMesh(StaticMeshWeapon);
}
