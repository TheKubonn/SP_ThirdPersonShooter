// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMainAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (MainCharacter == nullptr)
	{
		MainCharacter = Cast <AMainCharacter>(TryGetPawnOwner());
	}
	if (MainCharacter)
	{
		// Get the lateral speed of the character from velocity
		FVector Velocity = MainCharacter->GetVelocity();
		Velocity.Z = 0.f;
		Speed = Velocity.Size();

		// is character in the air?
		bIsInAir = MainCharacter->GetCharacterMovement()->IsFalling();

		// is character accelerating?
		bIsAccelerating = MainCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
		
		FRotator AimRotation = MainCharacter->GetBaseAimRotation();
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(MainCharacter->GetVelocity());
		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;

		if (MainCharacter->GetVelocity().Size() > 0.f)
		{
			LastMovementOffsetYaw = MovementOffsetYaw;
		}
	}
}

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MainCharacter = Cast <AMainCharacter>(TryGetPawnOwner());
}
