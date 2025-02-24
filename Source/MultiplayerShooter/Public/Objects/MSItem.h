// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/MSBaseDataAsset.h"
#include "Core/MSFStructItem.h"
#include "MSItem.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class IMSInteractInteface;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSItem : public AActor
{
    GENERATED_BODY()

public:
    AMSItem();
    virtual void InitializeData(FItem InData); //Вызывается после спавна
    virtual void Use() {}
    FItem GetItemData() const;

protected:
    UPROPERTY(EditAnyWhere, Category = "Settings");
    FItem ItemData;
    UPROPERTY()
    UStaticMeshComponent* StaticMeshComponent;
    UPROPERTY()
    USphereComponent* SphereCollisionInteract;
    virtual void Init(bool LoadDefault = false){};

    UFUNCTION(CallInEditor, Category = "Settings")
    virtual void LoadDefaultSettings();
    UFUNCTION()
    virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult& SweepResult);
    void InteractionSwitch(bool Toggle);

private:
    IMSInteractInteface* CharacterInteract;

};
