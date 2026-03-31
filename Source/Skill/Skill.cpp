#include "Skill.h"
#include "MySpartaLog.h"


IMPLEMENT_MODULE(FSkillModule, Skill);

void FSkillModule::StartupModule()
{
	UE_LOG(LogMySpartaModule, Error, TEXT("Skill 모듈이 활성화되었습니다."));
}
void FSkillModule::ShutdownModule()
{
	UE_LOG(LogMySpartaModule, Error, TEXT("Skill 모듈이 종료되었습니다."));
}