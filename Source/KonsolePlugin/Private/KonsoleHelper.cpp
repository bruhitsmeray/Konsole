// Fill out your copyright notice in the Description page of Project Settings.


#include "KonsoleHelper.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

bool UKonsoleHelper::LoadText(FString FileName, FString& Output)
{
	return FFileHelper::LoadFileToString(Output, *(FPaths::ProjectDir() + FileName));
}

bool UKonsoleHelper::SaveText(FString Input, FString FileName)
{
	return FFileHelper::SaveStringToFile(Input, *(FPaths::ProjectDir() + FileName), FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}
