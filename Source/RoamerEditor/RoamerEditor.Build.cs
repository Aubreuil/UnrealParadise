// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RoamerEditor : ModuleRules
{
	public RoamerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UnrealEd", "Roamer" });
	}
}
