// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartInterface.h"
#include "AsyncTestActor.generated.h"

UCLASS()
class MULTI_THREADEDLOADING_API AAsyncTestActor : public AActor, public IPartInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsyncTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meshes")
	class UAL_StaticMeshComp* AsyncStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meshes")
	class UAL_SkeletalMeshComp* AsyncSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meshes")
	class USceneComponent* DefaultSceneRoot;
};
