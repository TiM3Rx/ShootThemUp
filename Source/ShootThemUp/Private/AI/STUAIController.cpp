// ShootThemUpGame


#include "AI/STUAIController.h"
#include "AI/STUAICharacter.h"
#include "Components/STUAIPerceptionComponent.h"
#include "Components/STURespawnComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


ASTUAIController::ASTUAIController()
{
    STUAIPerceptionComponent = CreateDefaultSubobject<USTUAIPerceptionComponent>("STUAIPerceptionComponent");
    SetPerceptionComponent(*STUAIPerceptionComponent);

    RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");

    bWantsPlayerState = true;
}

void ASTUAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    
    const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);
    if (STUCharacter)
    {
        RunBehaviorTree(STUCharacter->UBehaviorTreeAsset);
    }

}

void ASTUAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const auto AimActor = GetFocusOnActor();
    SetFocus(AimActor);
}

AActor* ASTUAIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;

    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
