// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/Interfaces/MSInteractInteface.h"
#include "MSBaseCharacter.generated.h"

class UMSInventoryComponent;
class UMSEquipmentComponent;
class USceneComponent;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSBaseCharacter : public ACharacter, public IMSInteractInteface
{
    GENERATED_BODY()

public:
    AMSBaseCharacter();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UMSInventoryComponent* InventoryComponent;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UMSEquipmentComponent* EquipmentComponent;
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    USceneComponent* SceneComponentPointAttach;

    virtual bool PickUp(FItem InItem) override;
};
