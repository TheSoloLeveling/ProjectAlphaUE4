// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGun.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ACharacterGun::ACharacterGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SkeletalMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ACharacterGun::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void ACharacterGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

