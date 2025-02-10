// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Core/MSBaseComponent.h"

FTimerManager& UMSBaseComponent::GetTimerManager()
{
    check(GetWorld());
    return GetWorld()->GetTimerManager();
}
