// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AL_SkeletalMeshComp.h"
#include "AL_StaticMeshComp.h"
#include "AL_PartData.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ESkeletalPart : uint8
{
	None,
	SkeletalPart_1,
	SkeletalPart_2,
	SkeletalPart_3,
};

UENUM(BlueprintType)
enum class EStaticPart : uint8
{
	None,
	StaticPart_1,
	StaticPart_2,
	StaticPart_3,
};

UCLASS()
class MULTI_THREADEDLOADING_API UAL_PartData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	// array that gets filled when we call the async loader
	TArray<UAL_SkeletalMeshComp*> FoundSkeletalParts;
	TArray<UAL_StaticMeshComp*> FoundStaticParts;
	
	// hold all the object path
	TArray<FSoftObjectPath> ObjectsToUnload;

protected:
	// data used to fill in the data table
	UPROPERTY(EditAnywhere, Category= "AsyncHelperData")
	TArray<ESkeletalPart> SkeletalPartToFind;

	UPROPERTY(EditAnywhere, Category= "AsyncHelperData")
	TArray<EStaticPart> StaticPartToFind;

#pragma region Functions
	
	UFUNCTION(BlueprintCallable, Category= "DataAsyncLoadHelper")
	void RequestAsyncLoad_SkeletalPart(const UObject* DataOwner);

	UFUNCTION(BlueprintCallable, Category= "DataAsyncLoadHelper")
	void RequestAsyncLoad_StaticPart(const UObject* DataOwner);

	UFUNCTION(BlueprintCallable, Category= "DataAsyncUnloadHelper")
	void UnloadAllObjects(const UObject* DataOwner);

	UFUNCTION(BlueprintPure, Category= "DataAsyncGetters")
	TArray<UAL_SkeletalMeshComp*> GetAvailableSkeletalParts() const;

	UFUNCTION(BlueprintPure, Category= "DataAsyncGetters")
	TArray<UAL_StaticMeshComp*> GetAvailableStaticParts() const;

#pragma endregion

	// delegate
	UFUNCTION()
	void OnSkeletalPartsLoaded();
	
	UFUNCTION()
	void OnStaticPartsLoaded();

public:
	UPROPERTY(EditAnywhere, Category= "parts")
	TMap<ESkeletalPart, class TSoftClassPtr<UAL_SkeletalMeshComp>> AvailableSkeletalParts;

	UPROPERTY(EditAnywhere, Category= "parts")
	TMap<EStaticPart, class TSoftClassPtr<UAL_StaticMeshComp>> AvailableStaticParts;
};
