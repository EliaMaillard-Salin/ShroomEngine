#include "Logger.h"

#include <SDL_error.h>

using namespace shroom;

void Logger::Info(std::string const& message)
{
	SDL_Log(message.c_str());
}

void Logger::Error(LogType type, std::string const& message)
{
	SDL_LogError(static_cast<int>(type), "%s | SDL_Error : %s", message.c_str(), SDL_GetError());
}