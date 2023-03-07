// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Multi_ThreadedUE : ModuleRules
{
	public Multi_ThreadedUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
