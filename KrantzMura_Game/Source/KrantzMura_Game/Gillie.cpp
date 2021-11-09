// Fill out your copyright notice in the Description page of Project Settings.


#include "Gillie.h"

// Sets default values
AGillie::AGillie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//setting the size of the capsule in the code
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// settinf the pitch, roll and yaw of the camera to stop it flipping 
	bUseControllerRotationPitch = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;

	// getting the camera to move with the player
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	
	GetCharacterMovement()->JumpZVelocity = 300.0f;// speed we jump at
	GetCharacterMovement()->AirControl = 0.2f;// how much we can move the character in the air

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));// setting the name for it to find
	CameraBoom->SetupAttachment(RootComponent);// attches the camera to the Capsule Component in Gillie_BP as it is the root.

	CameraBoom->TargetArmLength = 300.0f; // this sets the distance from the character.
	CameraBoom->bUsePawnControlRotation = true; // Sets the rotation of the arm based on the controller.


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // this connects the camera to the boom.
	FollowCamera->bUsePawnControlRotation = false;// camera wont rotate relative to the arm

	
}



// Called when the game starts or when spawned
void AGillie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGillie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGillie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// binding the input

}

void AGillie::MoveForward(float Axis)
{
}

void AGillie::MoveRight(float Axis)
{
}

