// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KrantzMura_Game/Gillie_GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGillie_GameMode() {}
// Cross Module References
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AGillie_GameMode_NoRegister();
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AGillie_GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_KrantzMura_Game();
// End Cross Module References
	void AGillie_GameMode::StaticRegisterNativesAGillie_GameMode()
	{
	}
	UClass* Z_Construct_UClass_AGillie_GameMode_NoRegister()
	{
		return AGillie_GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGillie_GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGillie_GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_KrantzMura_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGillie_GameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Gillie_GameMode.h" },
		{ "ModuleRelativePath", "Gillie_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGillie_GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGillie_GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGillie_GameMode_Statics::ClassParams = {
		&AGillie_GameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AGillie_GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGillie_GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGillie_GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGillie_GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGillie_GameMode, 1393804136);
	template<> KRANTZMURA_GAME_API UClass* StaticClass<AGillie_GameMode>()
	{
		return AGillie_GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGillie_GameMode(Z_Construct_UClass_AGillie_GameMode, &AGillie_GameMode::StaticClass, TEXT("/Script/KrantzMura_Game"), TEXT("AGillie_GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGillie_GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
