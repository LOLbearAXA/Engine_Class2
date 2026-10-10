// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "AMainPlayerState.h"

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
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AATreasureChest::OnBeginOverlapComponentEvent);

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
	if (bCollected) {
		return;
	}
	else {
		bCollected = true;
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::White, TEXT("Collect"));
		}
	}
}

void AATreasureChest::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* tempChar = Cast<ACharacter>(OtherActor);

	if (tempChar){
		Collect();
		AAMainPlayerState* tempPS = tempChar->GetPlayerState<AAMainPlayerState>();

		if (tempPS) { // increase score
			tempPS->AddPlayerScore(5);
		}

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("Collide with Character"));
		}
	}
	
}
