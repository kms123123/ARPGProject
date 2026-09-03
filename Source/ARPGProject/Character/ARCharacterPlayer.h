// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARCharacterBase.h"
#include "ARCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARPGPROJECT_API AARCharacterPlayer : public AARCharacterBase
{
	GENERATED_BODY()
	
public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	TObjectPtr<class UInputAction> IA_Move;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	TObjectPtr<class UInputMappingContext> IMC_ThirdPerson;
};
