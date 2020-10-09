// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BullCowGame/Console/Cartridge.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCartridge() {}
// Cross Module References
	BULLCOWGAME_API UClass* Z_Construct_UClass_UCartridge_NoRegister();
	BULLCOWGAME_API UClass* Z_Construct_UClass_UCartridge();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BullCowGame();
// End Cross Module References
	void UCartridge::StaticRegisterNativesUCartridge()
	{
	}
	UClass* Z_Construct_UClass_UCartridge_NoRegister()
	{
		return UCartridge::StaticClass();
	}
	struct Z_Construct_UClass_UCartridge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCartridge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BullCowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCartridge_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Console/Cartridge.h" },
		{ "ModuleRelativePath", "Console/Cartridge.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCartridge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCartridge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCartridge_Statics::ClassParams = {
		&UCartridge::StaticClass,
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
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UCartridge_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCartridge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCartridge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCartridge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCartridge, 1222330714);
	template<> BULLCOWGAME_API UClass* StaticClass<UCartridge>()
	{
		return UCartridge::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCartridge(Z_Construct_UClass_UCartridge, &UCartridge::StaticClass, TEXT("/Script/BullCowGame"), TEXT("UCartridge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCartridge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
