// Fill out your copyright notice in the Description page of Project Settings.
#include "ATestActor.h"
#include "MySpartaLog.h"
#include "SkillActor/SkillBase.h"
#include"SkillActor/SorwdWave.h"
// Sets default values
AATestActor::AATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AATestActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogMySpartaModule, Display, TEXT("모듈적용성공?"));
}

// Called every frame
void AATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AATestActor::UsingSkill()
{
	if (!Skill) { return; }
	FVector SpawnLocation =
		GetActorLocation() 
	+ GetActorForwardVector()*100;
	
	FRotator Rotation = GetActorRotation();
	
	// 여기서 엑터를 스폰하고 스킬이 존재하면 날린다?
	ASkillBase* NewSkill = GetWorld()->SpawnActor<ASkillBase>(Skill,SpawnLocation,Rotation);
	if (NewSkill)
	{
		NewSkill->InitializeSkill(this);
	}
}

