// Copyright (c) 2025 Mazurik V.V. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/MSBaseCharacter.h"
#include "MSPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;

struct FInputActionValue;

UCLASS(Abstract)
class MULTIPLAYERSHOOTER_API AMSPlayerCharacter : public AMSBaseCharacter
{
	GENERATED_BODY()

public:
	AMSPlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USpringArmComponent* CameraBoom;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings | Input")
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
