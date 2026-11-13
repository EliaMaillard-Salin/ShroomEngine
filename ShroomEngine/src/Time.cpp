#include "Time.h"

#include <SDL_timer.h>
#include <algorithm>

using namespace shroom;

uint32 Time::m_startFrame = 0;
uint32 Time::m_lastFrame = 0;
uint32 Time::m_frameTime = 0;
float Time::deltaTime = 0;

uint32 Time::ComputeDeltaTime()
{
	m_startFrame = SDL_GetTicks();
	uint32 dt = m_startFrame - m_lastFrame;
	m_lastFrame = m_startFrame;
	dt = std::min(dt, MAX_DT);
	deltaTime = dt / 1000.0f;
	return dt;
}

void Time::DelayTime()
{
	m_frameTime = SDL_GetTicks() - m_startFrame;
	if (m_frameTime < FRAME_DELAY)
		SDL_Delay(FRAME_DELAY - m_frameTime);
}