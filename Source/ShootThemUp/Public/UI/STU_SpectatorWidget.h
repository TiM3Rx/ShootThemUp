// ShootThemUpGame

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STU_SpectatorWidget.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTU_SpectatorWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public:
    UFUNCTION(BlueprintCallable, Category = "UI")
        bool GetRespawnTime(int32& CountDownTime) const;

};
