// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/MSFStructItem.h"
#include "MSEquipmentInterface.generated.h"

UINTERFACE(MinimalAPI)
class UMSEquipmentInterface : public UInterface
{
    GENERATED_BODY()
};

class MULTIPLAYERSHOOTER_API IMSEquipmentInterface
{
    GENERATED_BODY()

public:
    virtual void SelectItem(FItem& InItem, bool Respawn = true) = 0;
    virtual FItem GetCurrentItem() const = 0;
};
