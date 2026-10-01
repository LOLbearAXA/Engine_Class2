// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"

// Sets default values
AATreasureChest::AATreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Init our treasure mesh
	TreasureMesh = CreateDefaultSubobject<UStaticMeshComponent>("TreasureMesh");

	TreasureMesh->SetGenerateOverlapEvents(false);

	// Init the box collider
	BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collision Detection");

	SetRootComponent(BoxCollider);

	TreasureMesh->SetupAttachment(BoxCollider);

	bCollected = false;

}

// Called when the game starts or when spawned
void AATreasureChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AATreasureChest::Collect() {
	
}

void AATreasureChest::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}
