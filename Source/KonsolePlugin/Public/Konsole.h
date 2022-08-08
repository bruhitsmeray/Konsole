// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"
#include "KonsoleMessage.h"
#include "WinMan.h"
#include "Konsole.generated.h"

/**
 * 
 */
UCLASS()
class KONSOLEPLUGIN_API UKonsole : public UWinMan
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Konsole|Code")
		FString Code;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Konsole|Code")
		FLinearColor CodeColor = FLinearColor(255, 255, 255);
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Konsole|Code")
		TArray<FString> CodeArray{
			"Notice",
			"Message",
			"Warning",
			"Error",
			"Command"
		};
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Konsole|Code")
		int CodeArrayIndex;

	UFUNCTION(BlueprintCallable, Category="Konsole|Code")
		void SwitchCode();
	UFUNCTION(BlueprintCallable, Category="Konsole|Code")
		void SwitchCodeColor();
	UFUNCTION(BlueprintCallable, Category="Konsole")
		void ClearInputBox(UEditableTextBox* InputBox);
	
	UFUNCTION(BlueprintCallable, Category="Konsole|Setup")
		void ConfigMouse();
	UFUNCTION(BlueprintCallable, Category="Konsole|Setup")
		void ConfigSelfReferences(UScrollBox* InMessageBox, TSubclassOf<class UKonsoleMessage> InMessageReference);

	UFUNCTION(BlueprintCallable, Category="Konsole")
		static void PrintToConsole(FString InSender, FString InCode, FString InMessage);
};
