﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTestActor.h"


// Sets default values
AAsyncTestActor::AAsyncTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsyncTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsyncTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

