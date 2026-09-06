// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCharacterPlayer.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AARCharacterPlayer::AARCharacterPlayer()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AARCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AARCharacterPlayer::Move);
	EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AARCharacterPlayer::Look);
	EnhancedInputComponent->BindAction(IA_Run, ETriggerEvent::Triggered, this, &AARCharacterPlayer::ChangeWalkRunMode, true);
	EnhancedInputComponent->BindAction(IA_Run, ETriggerEvent::Completed, this, &AARCharacterPlayer::ChangeWalkRunMode, false);
}

void AARCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (SubSystem)
		{
			SubSystem->AddMappingContext(IMC_ThirdPerson, 0);
		}
	}
}

void AARCharacterPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();
	
	const FRotator ControllerRotator = GetController()->GetControlRotation();
	const FRotator YawRotation(0.f, ControllerRotator.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	AddMovementInput(ForwardDirection, MoveVector.Y);
	AddMovementInput(RightDirection, MoveVector.X);
}

void AARCharacterPlayer::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void AARCharacterPlayer::ChangeWalkRunMode(const FInputActionValue& Value, bool bIsRun)
{
	GetCharacterMovement()->MaxWalkSpeed = bIsRun ? RunSpeed : WalkSpeed;
}
