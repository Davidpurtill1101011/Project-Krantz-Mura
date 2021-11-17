// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KrantzMura_Game/Tanaka.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTanaka() {}
// Cross Module References
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_ATanaka_NoRegister();
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_ATanaka();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_KrantzMura_Game();
// End Cross Module References
	void ATanaka::StaticRegisterNativesATanaka()
	{
	}
	UClass* Z_Construct_UClass_ATanaka_NoRegister()
	{
		return ATanaka::StaticClass();
	}
	struct Z_Construct_UClass_ATanaka_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATanaka_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_KrantzMura_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATanaka_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Tanaka.h" },
		{ "ModuleRelativePath", "Tanaka.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATanaka_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATanaka>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATanaka_Statics::ClassParams = {
		&ATanaka::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_ATanaka_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATanaka_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATanaka()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATanaka_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATanaka, 4004322691);
	template<> KRANTZMURA_GAME_API UClass* StaticClass<ATanaka>()
	{
		return ATanaka::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATanaka(Z_Construct_UClass_ATanaka, &ATanaka::StaticClass, TEXT("/Script/KrantzMura_Game"), TEXT("ATanaka"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATanaka);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
