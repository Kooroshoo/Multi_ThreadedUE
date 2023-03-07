// Fill out your copyright notice in the Description page of Project Settings.


#include "AL_PartData.h"
#include "AL_SkeletalMeshComp.h"
#include "AL_StaticMeshComp.h"
#include "AL_GameInstance.h"

void UAL_PartData::RequestAsyncLoad_SkeletalPart(const UObject* DataOwner)
{
	// check if available parts && key arrays have more than 0 indexes
	if (AvailableSkeletalParts.Num() > 0 && SkeletalPartToFind.Num() > 0)
	{
		// create an asset path list
		TArray<FSoftObjectPath> AssetToLoad;

		// iterate over all incoming key names and then find the value of that key in our TMAP
		for (int Index = 0; Index < SkeletalPartToFind.Num(); ++Index)
		{
			const ESkeletalPart PartName = SkeletalPartToFind[Index];
			// add that found object to both list & our object to unload arrays
			AssetToLoad.AddUnique(AvailableSkeletalParts.Find(PartName)->ToSoftObjectPath());
			ObjectsToUnload.AddUnique(AvailableSkeletalParts.Find(PartName)->ToSoftObjectPath());
		}
		
		// once the array is filled get our asset loader to load our array
		UAL_GameInstance* MyGameInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());

		if (!MyGameInstance) { return; }

		MyGameInstance->AssetLoader.RequestAsyncLoad(AssetToLoad, FStreamableDelegate::CreateUObject(this, &UAL_PartData::OnSkeletalPartsLoaded));
	}


}

void UAL_PartData::RequestAsyncLoad_StaticPart(const UObject* DataOwner)
{
	// check if available parts && key arrays have more than 0 indexes
	if (AvailableStaticParts.Num() > 0 && StaticPartToFind.Num() > 0)
	{
		// create an asset path list
		TArray<FSoftObjectPath> AssetToLoad;

		// iterate over all incoming key names and then find the value of that key in our TMAP
		for (int Index = 0; Index < StaticPartToFind.Num(); ++Index)
		{
			const EStaticPart PartName = StaticPartToFind[Index];
			// add that found object to both list & our object to unload arrays
			AssetToLoad.AddUnique(AvailableStaticParts.Find(PartName)->ToSoftObjectPath());
			ObjectsToUnload.AddUnique(AvailableStaticParts.Find(PartName)->ToSoftObjectPath());
		}
		
		// once the array is filled get our asset loader to load our array
		UAL_GameInstance* MyGameInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());

		if (!MyGameInstance) { return; }

		MyGameInstance->AssetLoader.RequestAsyncLoad(AssetToLoad, FStreamableDelegate::CreateUObject(this, &UAL_PartData::OnStaticPartsLoaded));
	}
}

void UAL_PartData::UnloadAllObjects(const UObject* DataOwner)
{
	// get our game instance
	UAL_GameInstance* MyGameOInstance = Cast<UAL_GameInstance>(DataOwner->GetWorld()->GetGameInstance());

	// if game instance is valid or if array is not empty
	if (!MyGameOInstance || ObjectsToUnload.Num() <= 0) { return; }
	
	// empty both of arrays
	FoundSkeletalParts.Empty();
	FoundStaticParts.Empty();
	
	// iterate over our objectToUnload array
	for (int Index = 0; Index < ObjectsToUnload.Num(); ++Index)
	{
		// create a const temp variable to hold the name of the object at the array index
		const FSoftObjectPath& PathName = ObjectsToUnload[Index];
		// unload that object
		MyGameOInstance->AssetLoader.Unload(PathName);

		
	}

}

TArray<UAL_SkeletalMeshComp*> UAL_PartData::GetAvailableSkeletalParts() const
{
	return FoundSkeletalParts;
}

TArray<UAL_StaticMeshComp*> UAL_PartData::GetAvailableStaticParts() const
{
	return FoundStaticParts;
}

void UAL_PartData::OnSkeletalPartsLoaded()
{
	// iterate over available skeletal parts and find the object of the key name and then add that object to our found part array
	for (int Index = 0; Index < SkeletalPartToFind.Num(); ++Index)
	{
		const ESkeletalPart PartName = SkeletalPartToFind[Index];
		FoundSkeletalParts.AddUnique(AvailableSkeletalParts.Find(PartName)->Get()->GetDefaultObject<UAL_SkeletalMeshComp>());
	}
}

void UAL_PartData::OnStaticPartsLoaded()
{
	// iterate over available skeletal parts and find the object of the key name and then add that object to our found part array
	for (int Index = 0; Index < StaticPartToFind.Num(); ++Index)
	{
		const EStaticPart PartName = StaticPartToFind[Index];
		FoundStaticParts.AddUnique(AvailableStaticParts.Find(PartName)->Get()->GetDefaultObject<UAL_StaticMeshComp>());
	}
}
