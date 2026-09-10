// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Ollama.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOllama() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT_API UClass* Z_Construct_UClass_AOllama();
MYPROJECT_API UClass* Z_Construct_UClass_AOllama_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AOllama Function GetAIResponse *******************************************
struct Z_Construct_UFunction_AOllama_GetAIResponse_Statics
{
	struct Ollama_eventGetAIResponse_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Ollama.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAIResponse constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAIResponse constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAIResponse Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOllama_GetAIResponse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Ollama_eventGetAIResponse_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOllama_GetAIResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOllama_GetAIResponse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_GetAIResponse_Statics::PropPointers) < 2048);
// ********** End Function GetAIResponse Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOllama_GetAIResponse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOllama, nullptr, "GetAIResponse", 	Z_Construct_UFunction_AOllama_GetAIResponse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_GetAIResponse_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOllama_GetAIResponse_Statics::Ollama_eventGetAIResponse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_GetAIResponse_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOllama_GetAIResponse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOllama_GetAIResponse_Statics::Ollama_eventGetAIResponse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOllama_GetAIResponse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOllama_GetAIResponse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOllama::execGetAIResponse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAIResponse();
	P_NATIVE_END;
}
// ********** End Class AOllama Function GetAIResponse *********************************************

// ********** Begin Class AOllama Function SendMessage *********************************************
struct Z_Construct_UFunction_AOllama_SendMessage_Statics
{
	struct Ollama_eventSendMessage_Parms
	{
		FString UserMessage;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Ollama.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendMessage constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_UserMessage;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendMessage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendMessage Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOllama_SendMessage_Statics::NewProp_UserMessage = { "UserMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Ollama_eventSendMessage_Parms, UserMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserMessage_MetaData), NewProp_UserMessage_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOllama_SendMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Ollama_eventSendMessage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOllama_SendMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOllama_SendMessage_Statics::NewProp_UserMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOllama_SendMessage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_SendMessage_Statics::PropPointers) < 2048);
// ********** End Function SendMessage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOllama_SendMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOllama, nullptr, "SendMessage", 	Z_Construct_UFunction_AOllama_SendMessage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_SendMessage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOllama_SendMessage_Statics::Ollama_eventSendMessage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOllama_SendMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOllama_SendMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOllama_SendMessage_Statics::Ollama_eventSendMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOllama_SendMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOllama_SendMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOllama::execSendMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_UserMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->SendMessage(Z_Param_UserMessage);
	P_NATIVE_END;
}
// ********** End Class AOllama Function SendMessage ***********************************************

// ********** Begin Class AOllama ******************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOllama;
UClass* AOllama::GetPrivateStaticClass()
{
	using TClass = AOllama;
	if (!Z_Registration_Info_UClass_AOllama.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("Ollama"),
			Z_Registration_Info_UClass_AOllama.InnerSingleton,
			StaticRegisterNativesAOllama,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AOllama.InnerSingleton;
}
UClass* Z_Construct_UClass_AOllama_NoRegister()
{
	return AOllama::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOllama_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Ollama.h" },
		{ "ModuleRelativePath", "Ollama.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AOllama constinit property declarations **********************************
// ********** End Class AOllama constinit property declarations ************************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAIResponse"), .Pointer = &AOllama::execGetAIResponse },
		{ .NameUTF8 = UTF8TEXT("SendMessage"), .Pointer = &AOllama::execSendMessage },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOllama_GetAIResponse, "GetAIResponse" }, // 3679679654
		{ &Z_Construct_UFunction_AOllama_SendMessage, "SendMessage" }, // 703042637
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOllama>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOllama_Statics
UObject* (*const Z_Construct_UClass_AOllama_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOllama_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOllama_Statics::ClassParams = {
	&AOllama::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOllama_Statics::Class_MetaDataParams), Z_Construct_UClass_AOllama_Statics::Class_MetaDataParams)
};
void AOllama::StaticRegisterNativesAOllama()
{
	UClass* Class = AOllama::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AOllama_Statics::Funcs));
}
UClass* Z_Construct_UClass_AOllama()
{
	if (!Z_Registration_Info_UClass_AOllama.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOllama.OuterSingleton, Z_Construct_UClass_AOllama_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOllama.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOllama);
AOllama::~AOllama() {}
// ********** End Class AOllama ********************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOllama, AOllama::StaticClass, TEXT("AOllama"), &Z_Registration_Info_UClass_AOllama, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOllama), 3800535703U) },
	};
}; // Z_CompiledInDeferFile_FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h__Script_MyProject_2261847013{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
