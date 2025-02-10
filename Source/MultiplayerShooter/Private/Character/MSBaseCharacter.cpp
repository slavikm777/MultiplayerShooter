// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Character/MSBaseCharacter.h"
#include "Character/Components/MSInventoryComponent.h"

AMSBaseCharacter::AMSBaseCharacter()
{
	InventoryComponent = CreateDefaultSubobject<UMSInventoryComponent>(TEXT("InventoryComponent"));
	check(InventoryComponent);
}
