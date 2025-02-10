// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MSBaseDataAsset.generated.h"

UCLASS()
class UMSBaseDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    UTexture2D* Icon;
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FText Name;
};
