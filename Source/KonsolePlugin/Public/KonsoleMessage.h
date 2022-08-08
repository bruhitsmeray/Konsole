// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KonsoleMessage.generated.h"

/**
 * 
 */
UCLASS()
class KONSOLEPLUGIN_API UKonsoleMessage : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Konsole|Data")
		FString DateStr;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|Data", meta = (ExposeOnSpawn = true))
		FString SenderStr;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|Data", meta = (ExposeOnSpawn = true))
		FString CodeStr;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|Data", meta = (ExposeOnSpawn = true))
		FString MessageStr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|ColorCodes")
		FLinearColor Notice = FLinearColor(0, 95, 255, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|ColorCodes")
		FLinearColor Message = FLinearColor(255, 255, 255, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|ColorCodes")
		FLinearColor Warning = FLinearColor(1, 0.75, 0, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Konsole|ColorCodes")
		FLinearColor Error = FLinearColor(1, 0, 0, 1);

	UFUNCTION(BlueprintCallable, Category = "Konsole|Message")
		void SetSender(FString InSender);
	UFUNCTION(BlueprintCallable, Category = "Konsole|Message")
		void SetCode(FString InCode);
	UFUNCTION(BlueprintCallable, Category = "Konsole|Message")
		void SetMessage(FString InMessage);
	UFUNCTION(BlueprintCallable, Category = "Konsole|Message")
		FLinearColor GetColorCode();
};
