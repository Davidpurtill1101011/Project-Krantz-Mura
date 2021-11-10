// Fill out your copyright notice in the Description page of Project Settings.


#include "Gillie.h"

// Sets default values
AGillie::AGillie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// controller rotates the player and not the mouse
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Sets the direction we are moving we are moving
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);// how much we rotate
	GetCharacterMovement()->JumpZVelocity = 300.f; //jump height
	GetCharacterMovement()->AirControl = 0.2f;// how much we can move the player in the air

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));// Createing a camera boom
	CameraBoom->SetupAttachment(RootComponent); // setting this to the root of the heirarchy

	CameraBoom->TargetArmLength = 300.f;// how far away the camera is from the player
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));// Creating the follow camera
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);// attatching the follow camera to the cameraboom

	FollowCamera->bUsePawnControlRotation = false;
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
	// -> Pointer
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);// controlling the yaw rotation// Turn is from the input setting in Project Setting in Unreal
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); // setting the camera to look up and down

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);// on press the jump happens
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);// on relese we stop the jumping from happening

	PlayerInputComponent->BindAxis("MoveForward", this, &AGillie::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGillie::MoveRight);

}

void AGillie::MoveForward(float Value)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);// making the character move forward or back
	AddMovementInput(Dir, Value);


}

void AGillie::MoveRight(float Value)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);// making the character move Left or right
	AddMovementInput(Dir, Value);
}

