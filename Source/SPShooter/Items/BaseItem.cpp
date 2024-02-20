// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemMesh"));
	SetRootComponent(ItemMesh);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(ItemMesh);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(RootComponent);
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

