// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/MSBasePlayerController.h"
#include "Components/InputComponent.h"
#include "Core/Settings/MSGameSettings.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Engine/AssetManager.h"

void AMSBasePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Получаем настройки игры и загружаем DefaultInputMappingContext
    const UMSGameSettings* GameSettings = GetDefault<UMSGameSettings>();
    check(GameSettings);
    FSoftObjectPath AssetPath = GameSettings->DefaultInputMappingContext.ToSoftObjectPath();

    // Начинаем асинхронную загрузку
    FStreamableManager& Streamable = UAssetManager::Get().GetStreamableManager();
    StreamableHandle = Streamable.RequestAsyncLoad(
        AssetPath, FStreamableDelegate::CreateUObject(this, &AMSBasePlayerController::OnInputMappingContextLoaded));
}

void AMSBasePlayerController::OnInputMappingContextLoaded()
{
    const UMSGameSettings* GameSettings = GetDefault<UMSGameSettings>();
    check(GameSettings);
    UInputMappingContext* DefaultInputMappingContext = Cast<UInputMappingContext>(StreamableHandle->GetLoadedAsset());
    UEnhancedInputLocalPlayerSubsystem* Subsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (Subsystem)
    {
        Subsystem->ClearAllMappings();
        check(DefaultInputMappingContext);
        Subsystem->AddMappingContext(DefaultInputMappingContext, 0);
    }
    StreamableHandle.Reset();
}

void AMSBasePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    UEnhancedInputComponent* NewInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    check(NewInputComponent);
    /*
    Bind some actions
    */
}
