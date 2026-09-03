// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCharacterPlayer.h"

#include "EnhancedInputComponent.h"

void AARCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AARCharacterPlayer::Move);
}
