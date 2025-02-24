// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/MSFStructItem.h"
#include "MSInventoryInterface.generated.h"

UINTERFACE(MinimalAPI)
class UMSInventoryInterface : public UInterface
{
    GENERATED_BODY()
};

class MULTIPLAYERSHOOTER_API IMSInventoryInterface
{
    GENERATED_BODY()

public:
    virtual void UpdateItem(FItem InItem) = 0;
};
