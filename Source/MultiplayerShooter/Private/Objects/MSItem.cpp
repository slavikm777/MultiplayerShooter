// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#include "Objects/MSItem.h"
#include "Components/SphereComponent.h"

AMSItem::AMSItem()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	check(StaticMeshComponent);
	SetRootComponent(StaticMeshComponent);
	SphereCollisionInteract = CreateDefaultSubobject< USphereComponent>(TEXT("CollisionInteract"));
	check(SphereCollisionInteract);
	SphereCollisionInteract->SetupAttachment(RootComponent);
	SphereCollisionInteract->SetSphereRadius(125.0f);
}
