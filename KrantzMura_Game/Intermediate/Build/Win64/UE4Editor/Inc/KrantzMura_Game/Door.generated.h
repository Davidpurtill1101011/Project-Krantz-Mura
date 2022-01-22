// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef KRANTZMURA_GAME_Door_generated_h
#error "Door.generated.h already included, missing '#pragma once' in Door.h"
#endif
#define KRANTZMURA_GAME_Door_generated_h

#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_SPARSE_DATA
#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_RPC_WRAPPERS
#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADoor(); \
	friend struct Z_Construct_UClass_ADoor_Statics; \
public: \
	DECLARE_CLASS(ADoor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/KrantzMura_Game"), NO_API) \
	DECLARE_SERIALIZER(ADoor)


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_INCLASS \
private: \
	static void StaticRegisterNativesADoor(); \
	friend struct Z_Construct_UClass_ADoor_Statics; \
public: \
	DECLARE_CLASS(ADoor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/KrantzMura_Game"), NO_API) \
	DECLARE_SERIALIZER(ADoor)


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoor(ADoor&&); \
	NO_API ADoor(const ADoor&); \
public:


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoor(ADoor&&); \
	NO_API ADoor(const ADoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADoor)


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DoorMesh() { return STRUCT_OFFSET(ADoor, DoorMesh); } \
	FORCEINLINE static uint32 __PPO__OpenAnimation() { return STRUCT_OFFSET(ADoor, OpenAnimation); } \
	FORCEINLINE static uint32 __PPO__CloseAnimation() { return STRUCT_OFFSET(ADoor, CloseAnimation); }


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_11_PROLOG
#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_PRIVATE_PROPERTY_OFFSET \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_SPARSE_DATA \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_RPC_WRAPPERS \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_INCLASS \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_PRIVATE_PROPERTY_OFFSET \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_SPARSE_DATA \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_INCLASS_NO_PURE_DECLS \
	KrantzMura_Game_Source_KrantzMura_Game_Door_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> KRANTZMURA_GAME_API UClass* StaticClass<class ADoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KrantzMura_Game_Source_KrantzMura_Game_Door_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
