// ShootThemUpGame


#include "STUGameInstance.h"
#include "Sound/STUSoundFuncLib.h"

void USTUGameInstance::ToggleVolume() 
{
    USTUSoundFuncLib::ToggleSoundClassVolume(MasterSoundClass);



}