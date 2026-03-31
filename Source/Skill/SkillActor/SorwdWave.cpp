// Fill out your copyright notice in the Description page of Project Settings.


#include "SorwdWave.h"
#include "MySpartaLog.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
ASwordWave::ASwordWave()
{
	PrimaryActorTick.bCanEverTick = false;
	CollisionComp= CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->SetBoxExtent(FVector(100.f, 100.0f, 20.0f) );
	//??
	CollisionComp->SetCollisionProfileName(TEXT("Projectile"));
	RootComponent = CollisionComp;
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->MaxSpeed = 2000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
	
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComponent");
	NiagaraComponent->SetupAttachment(CollisionComp);
	
	InitialLifeSpan = 2.f;
	Damage = 10.f;
	
	UE_LOG(LogMySpartaModule, Error, TEXT("Sword Wave"));
	if (CollisionComp)
	{
		CollisionComp->OnComponentHit.AddDynamic(this, &ASwordWave::OnHit);
	}
	
}

void ASwordWave::BeginPlay()
{
	Super::BeginPlay();
	if (NiagaraComponent && NiagaraSystem)
	{
		NiagaraComponent->SetAsset(NiagaraSystem);
		NiagaraComponent->Activate();
	}
	
}
void ASwordWave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (CollisionComp)
	//{
		// 1. 현재 박스의 위치, 크기, 회전값 가져오기
		//FVector Center = CollisionComp->GetComponentLocation();
		//FVector Extent = CollisionComp->GetScaledBoxExtent();
		//FQuat Rotation = CollisionComp->GetComponentQuat();

		// 2. 디버그 박스 그리기
		// DrawDebugBox(
		// 	GetWorld(),
		// 	Center,        // 중심점
		// 	Extent,        // 크기 (반지름 개념)
		// 	Rotation,      // 회전
		// 	FColor::Red,   // 색상 (빨강)
		// 	false,         // 영구 지속 아님 (매 프레임 새로 그림)
		// 	-1.0f,         // 수명 (false일 때 무시됨)
		// 	0,             // 우선순위
		// 	2.0f           // 선 두께
		// );
	//}
}


void ASwordWave::OnHit(UPrimitiveComponent* HitComp,
                       AActor* OtherActor, 
                       UPrimitiveComponent* OtherComp, 
                       FVector NormalImpulse, 
                       const FHitResult& Hit)
{
	if (OtherActor&& OtherActor != OwnerActor)
	{
		UGameplayStatics::ApplyDamage(OtherActor
			,Damage,
			nullptr,
			this,
			nullptr);
	}
	
}


