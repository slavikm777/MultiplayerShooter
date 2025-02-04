// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MSGameSettings.generated.h"

class UInputMappingContext;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Game Settings"))
class MULTIPLAYERSHOOTER_API UMSGameSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:

    UPROPERTY(EditAnywhere, Config, Category = "Input")
    TSoftObjectPtr<UInputMappingContext> DefaultInputMappingContext;
};
