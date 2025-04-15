// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class kdy_2018112051EditorTarget : TargetRules {
	public kdy_2018112051EditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "kdy_2018112051" });
	}
}