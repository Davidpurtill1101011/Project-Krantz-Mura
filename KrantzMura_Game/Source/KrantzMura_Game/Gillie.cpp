// Fill out your copyright notice in the Description page of Project Settings.


#include "Gillie.h"
#include "Item.h"
#include <KrantzMura_Game/Public/InteractableInterface.h>
#include <KrantzMura_Game/Public/WeaponBase.h>


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
	GetCharacterMovement()->JumpZVelocity = 200.f; //jump height
	//GetCharacterMovement()->AirControl = 0.2f;// how much we can move the player in the air

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));// Createing a camera boom
	CameraBoom->SetupAttachment(RootComponent); // setting this to the root of the heirarchy

	CameraBoom->TargetArmLength = 450.f;// how far away the camera is from the player
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));// Creating the follow camera
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);// attatching the follow camera to the cameraboom

	FollowCamera->bUsePawnControlRotation = false;

	SprintSpeedMultiplier = 1.5f;
	WalkSpeed = 0.3f;

	TeamId = FGenericTeamId(0);

	// loading the montage
	static ConstructorHelpers::FObjectFinder<UAnimMontage>FightingMontageObj(TEXT("AnimMontage'/Game/Mannequin/Animations/Fighting/FIghting.FIghting'"));
	if (FightingMontageObj.Succeeded()) {// if this succecds we then can use the animation that has been made over in UE(Unreal Engine Editor)
		FightingMontage = FightingMontageObj.Object;
	}

	// sound cue
	static ConstructorHelpers::FObjectFinder<USoundCue>PunchSoundCueObject(TEXT("SoundCue'/Game/Other_Assets/Sounds/PunchSoundQue.PunchSoundQue'"));
	if (PunchSoundCueObject.Succeeded()) {
		PunchSoundCue = PunchSoundCueObject.Object;
		PunchAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PunchAudioComponent"));
		PunchAudioComponent->SetupAttachment(RootComponent);

	}

	//Fist Colliders 
	LeftFistCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftFistCollisionBox"));
	LeftFistCollision->SetupAttachment(RootComponent);
	LeftFistCollision->SetCollisionProfileName("NoCollision");


	RightFistCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightFistCollisionBox"));
	RightFistCollision->SetupAttachment(RootComponent);
	RightFistCollision->SetCollisionProfileName("NoCollision");
	PunchAudioComponent->bAutoActivate = false;
	if (PunchAudioComponent && PunchSoundCue) {
		PunchAudioComponent->SetSound(PunchSoundCue);
	}
	//weapon setup
	static ConstructorHelpers::FObjectFinder<UAnimMontage>SwordMontageObj(TEXT("AnimMontage'/Game/Mannequin/Animations/Fighting/SwordAnim.SwordAnim'"));
	if (SwordMontageObj.Succeeded()) {
		SwordMontage = SwordMontageObj.Object;
	}

	
}

// Called when the game starts or when spawned
void AGillie::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters SpawnParams;
	
	if (WeaponClass) {
		SpawnParams.bNoFail = true;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		FTransform WeaponTransform;
		WeaponTransform.SetLocation(FVector::ZeroVector);
		WeaponTransform.SetRotation(FQuat(FRotator::ZeroRotator));
		Weapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponClass, WeaponTransform, SpawnParams);
		if (Weapon) {
			Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("right_fist_col"));
		}
	}

	//collision components attach to sockets on transform definitions 
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
	LeftFistCollision->AttachToComponent(GetMesh(), AttachmentRules, "left_fist_col");
	LeftFistCollision->OnComponentHit.AddDynamic(this, &AGillie::AttackHit);
	LeftFistCollision->SetNotifyRigidBodyCollision(false);



	RightFistCollision->OnComponentHit.AddDynamic(this, &AGillie::AttackHit);
	RightFistCollision->AttachToComponent(GetMesh(), AttachmentRules, "right_fist_col");
	RightFistCollision->SetNotifyRigidBodyCollision(false);
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
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);// on relese we stop the jumping from happening#

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AGillie::StartCrouching);// on press the jump happens

	//PlayerInputComponent->BindAction("Interact", IE_Released, this, &AGillie::DoorInteract);// lets the character to interact with objects
	PlayerInputComponent->BindAction("Interact", IE_Released, this, &AGillie::ItemInteract);// lets the character to interact with objects

	PlayerInputComponent->BindAxis("MoveForward", this, &AGillie::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGillie::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AGillie::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AGillie::StopSprinting);

	PlayerInputComponent->BindAction("Walking", IE_Pressed, this, &AGillie::Walking);
	PlayerInputComponent->BindAction("Walking", IE_Released, this, &AGillie::StopWalking);

	// binding the action buttons
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AGillie::AttackInput);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AGillie::StopAttack);

	PlayerInputComponent->BindAction("WeaponAttack", IE_Pressed, this, &AGillie::WeaponAttack);
	PlayerInputComponent->BindAction("WeaponAttack", IE_Released, this, &AGillie::StopAttack);

	

}

void AGillie::ItemUse(TSubclassOf<AItem> ItemSubClass)
{
	
	if (ItemSubClass) {
		
		if (AItem* OnUseItem = ItemSubClass.GetDefaultObject()) {
			
			OnUseItem->Use(this);
		}
		uint8 Index = 0;
		for (FItem_Information& Item : InventoryItems) {

			if (Item.ItemClass == ItemSubClass) {
				
				Item.StackCount--;
				if (Item.StackCount <= 0) {

					InventoryItems.RemoveAt(Index);
				}
				break;
			}
			Index++;
		}
		UpdateInventoryWidget(InventoryItems);
	}
}

void AGillie::UpdatePlayerStats(float NewHunger, float NewHealth)
{
}

void AGillie::Inventory_Items()
{
	if (InventoryItems.Num()) 
	{
		AddItemToInventoryWidget(InventoryItems[InventoryItems.Num() - 1], InventoryItems);
	}
	
	
}

void AGillie::AddHealth(float Value)
{
	Health += Value;
	UpdatePlayerStats(Hunger, Health);
	UE_LOG(LogTemp, Warning, TEXT("ADDED HEALTH: %f"), Health);
}

void AGillie::RemoveHunger(float Value)
{
	Hunger -= Value;
	UpdatePlayerStats(Hunger, Health);
	UE_LOG(LogTemp, Warning, TEXT("Not Hungery: %f"), Hunger);
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

void AGillie::StartCrouching()
{
	
	if (GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
		
	}
	else
	{
		Crouch();
		GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	}
}

void AGillie::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= SprintSpeedMultiplier;
	
}

void AGillie::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed /= SprintSpeedMultiplier;
}

void AGillie::Walking()
{
	GetCharacterMovement()->MaxWalkSpeed *= WalkSpeed;
}

void AGillie::StopWalking()
{
	GetCharacterMovement()->MaxWalkSpeed /= WalkSpeed;
}

void AGillie::DoorInteract()
{
	FHitResult Hit;
	FVector Start = FollowCamera->GetComponentLocation();
	FVector End = Start + GetControlRotation().Vector() * 800.0f;

	FCollisionQueryParams QueryParams;
	// the linetrace doesnt pick up the player ie: Line goes from camera 
	// through the player and then you can interact with the object
	QueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, FCollisionObjectQueryParams(), QueryParams)) {
		if (AActor* Actor = Hit.GetActor()) {
			UE_LOG(LogTemp, Warning, TEXT("Actor Hit: %s"), *Actor->GetName());
			// temp ToggleDoor if it is the door that is hit
			if (ADoor* Door = Cast<ADoor>(Actor)) {
				Door->ToggleDoor();
			}

		}
	}
}

void AGillie::ItemInteract()
{
	
	FVector Start = FollowCamera->GetComponentLocation();
	FVector End = Start + GetControlRotation().Vector() * 500.0f;

	FHitResult Hit;

	FCollisionQueryParams Params;
	// the linetrace doesnt pick up the player ie: Line goes from camera 
	// through the player and then you can interact with the object
	Params.AddIgnoredActor(this);
	//LineTraceSingleByChannel will let the item you want to pick up(DESTORY) the object
	// this works differently to how the door works as to where the door stays put.
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params)) {
		if (IInteractableInterface* Interface = Cast<IInteractableInterface>(Hit.GetActor())) {
			Interface->Interact(this);
		}
	}
}

void AGillie::StartAttack()
{
	LeftFistCollision->SetCollisionProfileName("Weapon");
	LeftFistCollision->SetNotifyRigidBodyCollision(true);
	LeftFistCollision->SetGenerateOverlapEvents(true);

	RightFistCollision->SetCollisionProfileName("Weapon");
	RightFistCollision->SetNotifyRigidBodyCollision(true);
	RightFistCollision->SetGenerateOverlapEvents(true);
}

void AGillie::StopAttack()
{
	LeftFistCollision->SetCollisionProfileName("NoCollision");
	LeftFistCollision->SetNotifyRigidBodyCollision(false);
	LeftFistCollision->SetGenerateOverlapEvents(false);


	RightFistCollision->SetCollisionProfileName("NoCollision");
	RightFistCollision->SetNotifyRigidBodyCollision(false);
	RightFistCollision->SetGenerateOverlapEvents(false);

	Weapon->StopSlash();
}

void AGillie::AttackInput()
{
	if (WeaponClass == NULL) {	
		// when M1 is clicked it will pick 1 or 2 and throw a different style punch
		int PunchIndex = rand() % 2 + 1;
		//and add a random function to concat onto Start_
		FString MontageSection = "Start_" + FString::FromInt(PunchIndex);
		PlayAnimMontage(FightingMontage, .8f, FName(*MontageSection)); // plays the animations, how fast the animations run 
	}

}

void AGillie::WeaponAttack()
{
	Weapon->Slash();
	int SwordIndex = rand() % 2 + 1;
	FString SwordSwingMontage = "Start_" + FString::FromInt(SwordIndex);
	PlayAnimMontage(SwordMontage, .5f, FName(*SwordSwingMontage));
}

void AGillie::AttackHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (PunchAudioComponent && !PunchAudioComponent->IsPlaying()) {

		PunchAudioComponent->SetPitchMultiplier(FMath::RandRange(1.0f, 3.0f));
		PunchAudioComponent->Play(0.f);
	}
}

void AGillie::AddInventoryItem(FItem_Information Item_Info)
{
	bool bIsNewItem = true;
	
	for (FItem_Information& Item : InventoryItems) {
		
		if (Item.ItemClass == Item_Info.ItemClass) {
			if (Item_Info.StackCount > 1) {
				Item.StackCount += Item_Info.StackCount;
			}
			else {
				++Item.StackCount;
			}
			
			bIsNewItem = false;
			break;
		}
	}

	if (bIsNewItem) {
		UE_LOG(LogTemp, Warning, TEXT("New"));
		InventoryItems.Add(Item_Info);
		Inventory_Items();
	}
	else
	{
		UpdateInventoryWidget(InventoryItems);
	}
	
	
	
}

