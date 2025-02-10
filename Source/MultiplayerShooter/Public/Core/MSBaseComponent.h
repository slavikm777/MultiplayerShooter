// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MSBaseComponent.generated.h"

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API UMSBaseComponent : public UActorComponent
{
    GENERATED_BODY()

protected:
    FTimerManager& GetTimerManager();
};
