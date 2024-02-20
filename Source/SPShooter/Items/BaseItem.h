// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

class UBoxComponent;
class USkeletalMeshComponent;
class UWidgetComponent;

UCLASS()
class SPSHOOTER_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

	
private:
	// Box collider for line trace that will show HUD widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UBoxComponent> CollisionBox;

	// Skeletal mesh for the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	TObjectPtr <USkeletalMeshComponent> ItemMesh;

	// Pop up widget for when the player looks at the item
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UWidgetComponent> PickupWidget;
public:	
	FORCEINLINE TObjectPtr <UWidgetComponent> GetPickupWidget() const { return PickupWidget; }

};
