// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MSBaseCharacter.generated.h"

class UMSInventoryComponent;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMSBaseCharacter();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UMSInventoryComponent* InventoryComponent;
};
