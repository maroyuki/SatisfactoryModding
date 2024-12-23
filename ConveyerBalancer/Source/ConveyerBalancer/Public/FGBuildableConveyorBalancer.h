// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Buildables/FGBuildableConveyorAttachment.h"
#include "FGFactoryConnectionComponent.h"
#include "FGBuildableConveyorBalancer.generated.h"

/**
 * 
 */
UCLASS()
class CONVEYERBALANCER_API AFGBuildableConveyorBalancer : public AFGBuildableConveyorAttachment
{
	GENERATED_BODY()

public:
	AFGBuildableConveyorBalancer();

	// Begin AActor interface
		virtual void BeginPlay() override;
	// End AActor interface

	// Begin Factory_ interface
	//virtual void Factory_Tick(float deltaTime) override;
	// End Factory_ interface
	
	void SetInputsAndOutputs(TArray< UFGFactoryConnectionComponent* >&In, TArray< UFGFactoryConnectionComponent* >& Out);

	UFUNCTION(BlueprintCallable, Category = "ConveyerBalancer")
	TArray< UFGFactoryConnectionComponent* >& GetInputs();

	UFUNCTION(BlueprintCallable, Category = "ConveyerBalancer")
	TArray< UFGFactoryConnectionComponent* >& GetOutputs();
protected:
	// Begin AActor Interface
	//virtual void PostInitializeComponents() override;
	// End AActor Interface

	/** Cycles through the inputs, stores the input we want to check next. Index is for the mInputs array. */
	UPROPERTY(SaveGame, Meta = (NoAutoJson))
	int32 mCurrentInputIndex;

	/** Cycles through the outputs, stores the output we want to check next. Index is for the mOutpus array. */
	UPROPERTY(SaveGame, Meta = (NoAutoJson))
	int32 mCurrentOutputIndex;
};
