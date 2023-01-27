// Copyright Epic Games, Inc. All Rights Reserved.

#include "KonsolePlugin.h"

#define LOCTEXT_NAMESPACE "FKonsolePluginModule"

DEFINE_LOG_CATEGORY_STATIC(LogKonsole, All, All);

#define LOG(LogString)	UE_LOG(LogKonsole, Display, TEXT("%s"), *FString(LogString));
#define LOG_WARNING(LogString)	UE_LOG(LogKonsole, Warning, TEXT("%s"), *FString(LogString));
#define LOG_ERROR(LogString)	UE_LOG(LogKonsole, Error, TEXT("%s"), *FString(LogString));

void FKonsolePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	LOG("Initializing KonsolePlugin.");
}

void FKonsolePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	LOG("Shutting down KonsolePlugin.");
}

#undef LOG
#undef LOG_WARNING
#undef LOG_ERROR
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FKonsolePluginModule, KonsolePlugin)