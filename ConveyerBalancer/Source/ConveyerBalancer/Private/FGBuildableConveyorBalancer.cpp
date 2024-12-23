// Fill out your copyright notice in the Description page of Project Settings.


#include "FGBuildableConveyorBalancer.h"
#include "FGInventoryLibrary.h"

AFGBuildableConveyorBalancer::AFGBuildableConveyorBalancer() : Super() {
	this->mCurrentInputIndex = -1;
	this->mCurrentOutputIndex = -1;
	this->mFactoryTickFunction.TickGroup = ETickingGroup::TG_PrePhysics;
	this->mFactoryTickFunction.EndTickGroup = ETickingGroup::TG_PrePhysics;
	this->mFactoryTickFunction.bTickEvenWhenPaused = false;
	this->mFactoryTickFunction.bCanEverTick = true;
	this->mFactoryTickFunction.bStartWithTickEnabled = true;
	this->mFactoryTickFunction.bAllowTickOnDedicatedServer = true;
	this->mFactoryTickFunction.TickInterval = 0.0;

	if (!mBufferInventory)
	{
		mBufferInventory = UFGInventoryLibrary::CreateInventoryComponent(this, FName("mBufferInventory"));
		mBufferInventory->Resize(mInventorySize);
	}
#if !WITH_EDITOR
	// mBufferInventory->SetLocked(false);
#endif

}

void AFGBuildableConveyorBalancer::BeginPlay()
{ 
	Super::BeginPlay();
	//SetInputsAndOutputs(mInputs, mOutputs);
}


/*void AFGBuildableConveyorBalancer::Factory_Tick(float deltaTime)
{
	Super::Factory_Tick(deltaTime);
}

void AFGBuildableConveyorBalancer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//SetInputsAndOutputs(mInputs, mOutputs);
}*/

void AFGBuildableConveyorBalancer::SetInputsAndOutputs(TArray<UFGFactoryConnectionComponent*>& In,TArray<UFGFactoryConnectionComponent*>& Out)
{
	TInlineComponentArray<UFGFactoryConnectionComponent*> Conns;
	this->GetComponents<UFGFactoryConnectionComponent>(Conns);

	if (Conns.Num() >= 1)
	{
		In.Empty();
		Out.Empty();
		for (UFGFactoryConnectionComponent* Connection : Conns)
		{
			switch (Connection->GetDirection())
			{
			case EFactoryConnectionDirection::FCD_INPUT:
				In.Add(Connection);
				break;
			case EFactoryConnectionDirection::FCD_OUTPUT:
				Out.Add(Connection);
				break;
			}
		}

		if (In.Num() < 1)
		{
			UE_LOG(LogTemp, Error, TEXT("AFGBuildableConveyorBalancer::SetInputsAndOutputs No Inputs"))
		}
		else { mCurrentInputIndex = 0; }

		if (Out.Num() < 1)
		{
			UE_LOG(LogTemp, Error, TEXT("AFGBuildableConveyorBalancer::SetInputsAndOutputs No Outputs"))
		}
		else { mCurrentOutputIndex = 0; }
	}
}

TArray<UFGFactoryConnectionComponent*>& AFGBuildableConveyorBalancer::GetInputs()
{
	return mInputs;
}

TArray<UFGFactoryConnectionComponent*>& AFGBuildableConveyorBalancer::GetOutputs()
{
	return mOutputs;
}

