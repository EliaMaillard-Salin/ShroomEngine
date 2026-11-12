#ifndef CORE_LOGGER_H
#define CORE_LOGGER_H

#include <SDL_log.h>
#include <string>

namespace shroom
{
	enum class LogType
	{
		APPLICATION = SDL_LOG_CATEGORY_APPLICATION,
		ASSERT = SDL_LOG_CATEGORY_ASSERT,
		AUDIO = SDL_LOG_CATEGORY_AUDIO,
		ERROR = SDL_LOG_CATEGORY_ERROR,
		INPUT = SDL_LOG_CATEGORY_INPUT,
		RENDER = SDL_LOG_CATEGORY_RENDER,
		SYSTEM = SDL_LOG_CATEGORY_SYSTEM,
		TEST = SDL_LOG_CATEGORY_TEST,
		VIDEO = SDL_LOG_CATEGORY_VIDEO

	};

	class Logger
	{
	public:
		Logger() = delete;
		Logger(Logger const&) = delete;
		Logger& operator=(Logger const&) = delete;

		static void Info(std::string const& message);
		static void Error(LogType type, std::string const& message);
	};
};

#endif
