// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTestActor.h"

#include "AL_SkeletalMeshComp.h"
#include "AL_StaticMeshComp.h"


// Sets default values
AAsyncTestActor::AAsyncTestActor()
{
	
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = DefaultSceneRoot;
	
	AsyncSkeletalMesh = CreateDefaultSubobject<UAL_SkeletalMeshComp>(TEXT("SkeletalMeshComp"));
	AsyncSkeletalMesh->SetupAttachment(DefaultSceneRoot);
	AsyncStaticMesh = CreateDefaultSubobject<UAL_StaticMeshComp>(TEXT("StaticMeshComp"));
	AsyncStaticMesh->SetupAttachment(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void AAsyncTestActor::BeginPlay()
{
	Super::BeginPlay();

	AsyncSkeletalMesh->SetupAttachment(DefaultSceneRoot);
	AsyncStaticMesh->SetupAttachment(DefaultSceneRoot);
	
}


