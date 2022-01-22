// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KrantzMura_Game/DayNightCycle.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDayNightCycle() {}
// Cross Module References
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_ADayNightCycle_NoRegister();
	KRANTZMURA_GAME_API UClass* Z_Construct_UClass_ADayNightCycle();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_KrantzMura_Game();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ADirectionalLight_NoRegister();
// End Cross Module References
	void ADayNightCycle::StaticRegisterNativesADayNightCycle()
	{
	}
	UClass* Z_Construct_UClass_ADayNightCycle_NoRegister()
	{
		return ADayNightCycle::StaticClass();
	}
	struct Z_Construct_UClass_ADayNightCycle_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_sun_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_sun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_lightsource_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_lightsource;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_turnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_turnRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADayNightCycle_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_KrantzMura_Game,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADayNightCycle_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DayNightCycle.h" },
		{ "ModuleRelativePath", "DayNightCycle.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADayNightCycle_Statics::NewProp_sun_MetaData[] = {
		{ "Category", "Sky" },
		{ "Comment", "// slysphere property, can assign inside details panel, \n" },
		{ "ModuleRelativePath", "DayNightCycle.h" },
		{ "ToolTip", "slysphere property, can assign inside details panel," },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_sun = { "sun", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADayNightCycle, sun), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_sun_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_sun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADayNightCycle_Statics::NewProp_lightsource_MetaData[] = {
		{ "Category", "Sky" },
		{ "Comment", "// is an AActor, the parent class of unreal skysphere is an AActor\n" },
		{ "ModuleRelativePath", "DayNightCycle.h" },
		{ "ToolTip", "is an AActor, the parent class of unreal skysphere is an AActor" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_lightsource = { "lightsource", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADayNightCycle, lightsource), Z_Construct_UClass_ADirectionalLight_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_lightsource_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_lightsource_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADayNightCycle_Statics::NewProp_turnRate_MetaData[] = {
		{ "Category", "Sky" },
		{ "Comment", "// class type of our light source\n" },
		{ "ModuleRelativePath", "DayNightCycle.h" },
		{ "ToolTip", "class type of our light source" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_turnRate = { "turnRate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADayNightCycle, turnRate), METADATA_PARAMS(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_turnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::NewProp_turnRate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADayNightCycle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_sun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_lightsource,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_turnRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADayNightCycle_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADayNightCycle>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADayNightCycle_Statics::ClassParams = {
		&ADayNightCycle::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADayNightCycle_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADayNightCycle_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADayNightCycle()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADayNightCycle_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADayNightCycle, 846626519);
	template<> KRANTZMURA_GAME_API UClass* StaticClass<ADayNightCycle>()
	{
		return ADayNightCycle::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADayNightCycle(Z_Construct_UClass_ADayNightCycle, &ADayNightCycle::StaticClass, TEXT("/Script/KrantzMura_Game"), TEXT("ADayNightCycle"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADayNightCycle);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
