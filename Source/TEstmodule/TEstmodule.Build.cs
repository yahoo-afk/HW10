// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TEstmodule : ModuleRules
{
	public TEstmodule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"MySpartaLog",
			"Skill",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TEstmodule",
			"TEstmodule/Variant_Platforming",
			"TEstmodule/Variant_Platforming/Animation",
			"TEstmodule/Variant_Combat",
			"TEstmodule/Variant_Combat/AI",
			"TEstmodule/Variant_Combat/Animation",
			"TEstmodule/Variant_Combat/Gameplay",
			"TEstmodule/Variant_Combat/Interfaces",
			"TEstmodule/Variant_Combat/UI",
			"TEstmodule/Variant_SideScrolling",
			"TEstmodule/Variant_SideScrolling/AI",
			"TEstmodule/Variant_SideScrolling/Gameplay",
			"TEstmodule/Variant_SideScrolling/Interfaces",
			"TEstmodule/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
