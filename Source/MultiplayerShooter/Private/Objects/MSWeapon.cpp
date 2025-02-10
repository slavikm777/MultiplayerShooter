// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Objects/MSWeapon.h"

AMSWeapon::AMSWeapon()
{
	Init();
}

void AMSWeapon::Init()
{
	if (WeaponDataAsset)
	{
		StaticMeshWeapon = WeaponDataAsset->WeaponMesh;
		WeaponType = WeaponDataAsset->WeaponType;
		Damage = WeaponDataAsset->Damage;
	}
	else 
	{
		StaticMeshWeapon = nullptr;
		WeaponType = EWeaponType::Rifle;
		Damage = 0;
	}
}

void AMSWeapon::OnConstruction(const FTransform& Transform)
{
	Init();
	StaticMeshComponent->SetStaticMesh(StaticMeshWeapon);
}
