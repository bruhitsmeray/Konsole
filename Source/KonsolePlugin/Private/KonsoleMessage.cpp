// Fill out your copyright notice in the Description page of Project Settings.


#include "KonsoleMessage.h"

void UKonsoleMessage::SetSender(FString InSender)
{
	SenderStr = InSender;
}

void UKonsoleMessage::SetCode(FString InCode)
{
	CodeStr = InCode;
}

void UKonsoleMessage::SetMessage(FString InMessage)
{
	MessageStr = InMessage;
}

FLinearColor UKonsoleMessage::GetColorCode()
{
	if(CodeStr == "Notice") {
		return FLinearColor(0, 95, 255);
	}
	if (CodeStr == "Warning") {
		return FLinearColor(1, 0.75, 0);
	}
	if (CodeStr == "Error") {
		return FLinearColor(1, 0, 0);
	}
	return FLinearColor(255, 255, 255);
}
