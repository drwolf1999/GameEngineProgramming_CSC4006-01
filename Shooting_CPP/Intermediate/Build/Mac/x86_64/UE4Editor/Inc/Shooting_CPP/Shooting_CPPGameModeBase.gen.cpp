// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooting_CPP/Shooting_CPPGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooting_CPPGameModeBase() {}
// Cross Module References
	SHOOTING_CPP_API UClass* Z_Construct_UClass_AShooting_CPPGameModeBase_NoRegister();
	SHOOTING_CPP_API UClass* Z_Construct_UClass_AShooting_CPPGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Shooting_CPP();
// End Cross Module References
	void AShooting_CPPGameModeBase::StaticRegisterNativesAShooting_CPPGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AShooting_CPPGameModeBase_NoRegister()
	{
		return AShooting_CPPGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AShooting_CPPGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Shooting_CPP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Shooting_CPPGameModeBase.h" },
		{ "ModuleRelativePath", "Shooting_CPPGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooting_CPPGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::ClassParams = {
		&AShooting_CPPGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShooting_CPPGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShooting_CPPGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShooting_CPPGameModeBase, 3200016648);
	template<> SHOOTING_CPP_API UClass* StaticClass<AShooting_CPPGameModeBase>()
	{
		return AShooting_CPPGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShooting_CPPGameModeBase(Z_Construct_UClass_AShooting_CPPGameModeBase, &AShooting_CPPGameModeBase::StaticClass, TEXT("/Script/Shooting_CPP"), TEXT("AShooting_CPPGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooting_CPPGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
