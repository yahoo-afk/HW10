using UnrealBuildTool;

public class MySpartaLog : ModuleRules
{
	public MySpartaLog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(new string[] { "MySpartaLog" });
		PublicDependencyModuleNames.AddRange(new string[]
			{
				// Initial Modules
				"Core", "CoreUObject", "Engine", "InputCore","Niagara"
			}
		);

		PrivateDependencyModuleNames.AddRange(new string[] { });

	}
}