// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MSItem.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSItem : public AActor
{
    GENERATED_BODY()

public:
    AMSItem();

protected:
    UPROPERTY()
    UStaticMeshComponent* StaticMeshComponent;
    UPROPERTY()
    USphereComponent* SphereCollisionInteract;
    virtual void Init() {};
};
