// Copyright (c) 2025 Mazurik V.V. All rights reserved.


#include "Character/MSPlayerCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AMSPlayerCharacter::AMSPlayerCharacter()
{
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->TargetArmLength = 100.0f;
    CameraBoom->SetRelativeLocation(FVector(0, -50, 0));
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);
    GetCharacterMovement()->bOrientRotationToMovement = false;
    bUseControllerRotationYaw = true;
}

void AMSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(JumpAction);
    check(MoveAction);
    check(LookAction);
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMSPlayerCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMSPlayerCharacter::Look);
    }
}

void AMSPlayerCharacter::Move(const FInputActionValue& Value)
{
    check(GetController());
    FVector2D MovementVector = Value.Get<FVector2D>();
    const FRotator Rotation = GetController()->GetControlRotation();
    const FRotator YawRotation{ 0.0f, Rotation.Yaw, 0.0f };
    const FVector ForwardDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X) };
    const FVector RightDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y) };
    AddMovementInput(ForwardDirection, MovementVector.Y);
    AddMovementInput(RightDirection, MovementVector.X);
}

void AMSPlayerCharacter::Look(const FInputActionValue& Value)
{
    check(GetController());
    FVector2D LookVector = Value.Get<FVector2D>();
    AddControllerYawInput(LookVector.X);
    AddControllerPitchInput(LookVector.Y);
}
