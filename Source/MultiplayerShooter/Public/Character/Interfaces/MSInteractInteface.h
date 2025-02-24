// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Data/MSBaseDataAsset.h"
#include "Core/MSFStructItem.h"
#include "MSInteractInteface.generated.h"

UINTERFACE(MinimalAPI)
class UMSInteractInteface : public UInterface
{
    GENERATED_BODY()
};

class MULTIPLAYERSHOOTER_API IMSInteractInteface
{
    GENERATED_BODY()

public:
    virtual bool PickUp(FItem InItem) = 0;
};
