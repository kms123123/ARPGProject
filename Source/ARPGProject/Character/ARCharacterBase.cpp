// Fill out your copyright notice in the Description page of Project Settings.


#include "ARCharacterBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AARCharacterBase::AARCharacterBase()
{
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f,-80.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
}

void AARCharacterBase::Move()
{
}
