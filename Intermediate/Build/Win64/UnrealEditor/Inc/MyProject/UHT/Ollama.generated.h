// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Ollama.h"

#ifdef MYPROJECT_Ollama_generated_h
#error "Ollama.generated.h already included, missing '#pragma once' in Ollama.h"
#endif
#define MYPROJECT_Ollama_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AOllama ******************************************************************
#define FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSendMessage); \
	DECLARE_FUNCTION(execGetAIResponse);


struct Z_Construct_UClass_AOllama_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_AOllama_NoRegister();

#define FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOllama(); \
	friend struct ::Z_Construct_UClass_AOllama_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_AOllama_NoRegister(); \
public: \
	DECLARE_CLASS2(AOllama, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AOllama_NoRegister) \
	DECLARE_SERIALIZER(AOllama)


#define FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AOllama(AOllama&&) = delete; \
	AOllama(const AOllama&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOllama); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOllama); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOllama) \
	NO_API virtual ~AOllama();


#define FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_11_PROLOG
#define FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_INCLASS_NO_PURE_DECLS \
	FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AOllama;

// ********** End Class AOllama ********************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_unrealengine_Unreal_Projects_MyProject_Source_MyProject_Ollama_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
