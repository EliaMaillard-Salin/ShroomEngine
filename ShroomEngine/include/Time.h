#ifndef SHROOM_ENGINE_TIME_H
#define SHROOM_ENGINE_TIME_H

#include <Define.h>

namespace shroom
{
	class Time
	{
	public:

		Time() = default;
		Time(Time const&) = delete;
		Time operator=(Time const&) = delete;

		static uint32 ComputeDeltaTime();
		static void DelayTime();

		static float deltaTime;

	private:
		static uint32 const FPS = 60;
		static uint32 const FRAME_DELAY = 1000 / FPS;
		static uint32 const MAX_DT = 50;

		static uint32 m_startFrame;
		static uint32 m_lastFrame;
		static uint32 m_frameTime;
	};
};

#endif // !SHROOM_ENGINE_TIME_H
