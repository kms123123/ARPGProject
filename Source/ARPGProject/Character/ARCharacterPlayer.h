// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARCharacterBase.h"
#include "InputActionValue.h"
#include "ARCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARPGPROJECT_API AARCharacterPlayer : public AARCharacterBase
{
	GENERATED_BODY()
	
public:
	AARCharacterPlayer();
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess= true))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess= true))
	TObjectPtr<class UCameraComponent> CameraComponent;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	TObjectPtr<class UInputAction> IA_Move;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	TObjectPtr<class UInputMappingContext> IMC_ThirdPerson;
	
private:
	void Move(const FInputActionValue& Value);
};
