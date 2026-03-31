// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATestActor.generated.h"

class ASkillBase;
UCLASS()
class TESTMODULE_API AATestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	TSubclassOf<ASkillBase> Skill;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void UsingSkill();
};
