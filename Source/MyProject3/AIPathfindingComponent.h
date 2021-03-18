// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Queue.h"
#include "AIPathfindingComponent.generated.h"


USTRUCT(BlueprintType)
struct FNodeG
{
	GENERATED_USTRUCT_BODY()

	FNodeG* Parent;
	float H;
	FNodeG() {}
	FNodeG(float h)
	{
		H = h;
	}
	
};

USTRUCT(BlueprintType)
struct F_BSTset
{
	GENERATED_USTRUCT_BODY()

	FNodeG value;
	F_BSTset* left;
	F_BSTset* right;

	F_BSTset() {}
	F_BSTset(FNodeG n)
	{
		value = n;
		left = NULL;
		right = NULL;
	}

	F_BSTset* Insert(F_BSTset* ClosedSet, FNodeG n)
	{
		if (ClosedSet == NULL)
		{
			ClosedSet = new F_BSTset;
			ClosedSet->value = n;
			ClosedSet->left = NULL;
			ClosedSet->right = NULL;
		}
		else if (ClosedSet->value.H < n.H)
			ClosedSet->right = Insert(ClosedSet->right, n);
		else
			ClosedSet->left = Insert(ClosedSet->left, n);

		return ClosedSet;

	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT3_API UAIPathfindingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAIPathfindingComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
		FNodeG StartNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
		FNodeG EndNode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Set")    // doutes dans l'implementation
		F_BSTset ClosedSet = F_BSTset(StartNode);

	TQueue<FNodeG> OpenSet;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	
	

	
};
