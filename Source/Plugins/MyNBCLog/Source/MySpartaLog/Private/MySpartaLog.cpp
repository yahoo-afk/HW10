#include "MySpartaLog.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogMySpartaModule);

void FMySpartaLog::StartupModule()
{
	UE_LOG(LogMySpartaModule, Error, TEXT("MySpartaLog is Start"));
}

void FMySpartaLog::ShutdownModule() {}

IMPLEMENT_MODULE(FMySpartaLog, MySpartaLog);