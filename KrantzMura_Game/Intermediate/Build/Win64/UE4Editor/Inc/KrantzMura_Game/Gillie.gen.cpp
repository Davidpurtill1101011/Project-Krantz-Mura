// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KrantzMura_Game/Gillie.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGillie() {}
// Cross Module References
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AGillie_NoRegister();
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_AGillie();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_KrantzMura_Game();
// End Cross Module References
	void AGillie::StaticRegisterNativesAGillie()
	{
	}
	UClass* Z_Construct_UClass_AGillie_NoRegister()
	{
		return AGillie::StaticClass();
	}
	struct Z_Construct_UClass_AGillie_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGillie_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_KrantzMura_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGillie_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Gillie.h" },
		{ "ModuleRelativePath", "Gillie.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGillie_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGillie>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGillie_Statics::ClassParams = {
		&AGillie::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGillie_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGillie_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGillie()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGillie_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGillie, 1651940797);
	template<> KRANTZMURA_GAME_API UClass* StaticClass<AGillie>()
	{
		return AGillie::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGillie(Z_Construct_UClass_AGillie, &AGillie::StaticClass, TEXT("/Script/KrantzMura_Game"), TEXT("AGillie"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGillie);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
