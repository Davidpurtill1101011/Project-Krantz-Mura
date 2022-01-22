// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KrantzMura_Game/KrantzMura_GameGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKrantzMura_GameGameModeBase() {}
// Cross Module References
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AKrantzMura_GameGameModeBase_NoRegister();
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AKrantzMura_GameGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_KrantzMura_Game();
// End Cross Module References
	void AKrantzMura_GameGameModeBase::StaticRegisterNativesAKrantzMura_GameGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AKrantzMura_GameGameModeBase_NoRegister()
	{
		return AKrantzMura_GameGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_KrantzMura_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "KrantzMura_GameGameModeBase.h" },
		{ "ModuleRelativePath", "KrantzMura_GameGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKrantzMura_GameGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::ClassParams = {
		&AKrantzMura_GameGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AKrantzMura_GameGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AKrantzMura_GameGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AKrantzMura_GameGameModeBase, 2841853234);
	template<> KRANTZMURA_GAME_API UClass* StaticClass<AKrantzMura_GameGameModeBase>()
	{
		return AKrantzMura_GameGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AKrantzMura_GameGameModeBase(Z_Construct_UClass_AKrantzMura_GameGameModeBase, &AKrantzMura_GameGameModeBase::StaticClass, TEXT("/Script/KrantzMura_Game"), TEXT("AKrantzMura_GameGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKrantzMura_GameGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
