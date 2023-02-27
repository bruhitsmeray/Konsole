// Fill out your copyright notice in the Description page of Project Settings.


#include "Konsole.h"
#include "KonsoleHelper.h"
#include "EngineMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "TimerManager.h"

UScrollBox* MessageBoxRef = nullptr;
TSubclassOf<class UKonsoleMessage> MessageClass;
UKonsoleMessage* ConsoleMessage;

void UKonsole::SwitchCode()
{
	Code = CodeArray[CodeArrayIndex];
	if(CodeArrayIndex >= CodeArray.Num() - 1)
	{
		CodeArrayIndex = 0;
	} else {
		CodeArrayIndex = CodeArrayIndex + 1;
	}
	SwitchCodeColor();
}

void UKonsole::SwitchCodeColor()
{
	if(Code == "Notice") {
		CodeColor = FLinearColor(0, 95, 255);
	} else if (Code == "Warning") {
		CodeColor = FLinearColor(1, 0.75, 0);
	} else if (Code == "Error") {
		CodeColor = FLinearColor(1, 0, 0);
	} else if (Code == "Message" || Code == "Command") {
		CodeColor = FLinearColor(255, 255, 255);
	}
}

void UKonsole::ClearInputBox(UEditableTextBox* InputBox)
{
	InputBox->SetText(FText::GetEmpty());
}

void UKonsole::ConfigMouse()
{
	if(!CanvasRef->IsVisible())
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameAndUI());
	} else {
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(false);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
	}
}

void UKonsole::ConfigSelfReferences(UScrollBox* InMessageBox, TSubclassOf<UKonsoleMessage> InMessageReference)
{
	MessageBoxRef = InMessageBox;
	MessageClass = InMessageReference;
}

void UKonsole::PrintToConsole(FString InSender, FString InCode, FString InMessage)
{
	UWorld* World = GEngine->GameViewport->GetWorld();
	if(MessageBoxRef && MessageClass)
	{
		ConsoleMessage = CreateWidget<UKonsoleMessage>(World, MessageClass);
		ConsoleMessage->SetSender(InSender);
		ConsoleMessage->SetCode(InCode);
		ConsoleMessage->SetMessage(InMessage);

		MessageBoxRef->AddChild(ConsoleMessage);
		FTimerHandle TimerHandle;
		World->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			MessageBoxRef->ScrollToEnd();
		}, 0.02f, false);

		const FString LogTime = UKismetTextLibrary::AsDateTime_DateTime(FDateTime::Now()).ToString();
		FString OutputLog = FString::Printf(TEXT("%s: [%s]: (%s): %s"), *LogTime, *InSender, *InCode, *InMessage);
		if (InSender == "Client" || InSender == UKismetSystemLibrary::GetPlatformUserName() && InCode == "Notice") {
			UKonsoleHelper::SaveText(OutputLog.Append("\n"), *FString::Printf(TEXT("%s_notice.txt"), FApp::GetProjectName()));
		}
		else {
			UKonsoleHelper::SaveText(OutputLog.Append("\n"), *FString::Printf(TEXT("%s_log.log"), FApp::GetProjectName()));
		}
	} else {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *InMessage);
	}
}
