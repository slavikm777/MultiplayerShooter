// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Objects/MSItem.h"
#include "Components/SphereComponent.h"
#include "Core/Helpers/MSHelperFunctions.h"
#include "Character/Interfaces/MSInteractInteface.h"

AMSItem::AMSItem()
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    check(StaticMeshComponent);
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SetRootComponent(StaticMeshComponent);
    SphereCollisionInteract = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionInteract"));
    check(SphereCollisionInteract);
    InteractionSwitch(true);
    SphereCollisionInteract->SetupAttachment(RootComponent);
    SphereCollisionInteract->SetSphereRadius(125.0f);
    SphereCollisionInteract->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::BeginOverlap);
}

void AMSItem::InitializeData(FItem InData)
{
    ItemData = InData;
    InteractionSwitch(false);
}

FItem AMSItem::GetItemData() const
{
    return ItemData;
}

void AMSItem::LoadDefaultSettings()
{
}

void AMSItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    CharacterInteract = Cast<IMSInteractInteface>(OtherActor);
    if (CharacterInteract && CharacterInteract->PickUp(ItemData))
        Destroy();
}

void AMSItem::InteractionSwitch(bool Toggle)
{
    if (Toggle)
        SphereCollisionInteract->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    else
        SphereCollisionInteract->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
