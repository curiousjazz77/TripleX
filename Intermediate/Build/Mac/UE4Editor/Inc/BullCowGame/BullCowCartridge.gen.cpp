// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BullCowGame/BullCowCartridge.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBullCowCartridge() {}
// Cross Module References
	BULLCOWGAME_API UClass* Z_Construct_UClass_UBullCowCartridge_NoRegister();
	BULLCOWGAME_API UClass* Z_Construct_UClass_UBullCowCartridge();
	BULLCOWGAME_API UClass* Z_Construct_UClass_UCartridge();
	UPackage* Z_Construct_UPackage__Script_BullCowGame();
// End Cross Module References
	void UBullCowCartridge::StaticRegisterNativesUBullCowCartridge()
	{
	}
	UClass* Z_Construct_UClass_UBullCowCartridge_NoRegister()
	{
		return UBullCowCartridge::StaticClass();
	}
	struct Z_Construct_UClass_UBullCowCartridge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBullCowCartridge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCartridge,
		(UObject* (*)())Z_Construct_UPackage__Script_BullCowGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBullCowCartridge_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "BullCowCartridge.h" },
		{ "ModuleRelativePath", "BullCowCartridge.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBullCowCartridge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBullCowCartridge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBullCowCartridge_Statics::ClassParams = {
		&UBullCowCartridge::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UBullCowCartridge_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBullCowCartridge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBullCowCartridge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBullCowCartridge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBullCowCartridge, 2375356710);
	template<> BULLCOWGAME_API UClass* StaticClass<UBullCowCartridge>()
	{
		return UBullCowCartridge::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBullCowCartridge(Z_Construct_UClass_UBullCowCartridge, &UBullCowCartridge::StaticClass, TEXT("/Script/BullCowGame"), TEXT("UBullCowCartridge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBullCowCartridge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
