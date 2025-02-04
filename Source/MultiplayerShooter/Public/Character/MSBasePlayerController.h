// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/StreamableManager.h"
#include "MSBasePlayerController.generated.h"

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSBasePlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	TSharedPtr<FStreamableHandle> StreamableHandle;
	void OnInputMappingContextLoaded();
};
