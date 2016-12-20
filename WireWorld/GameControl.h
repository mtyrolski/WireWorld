#pragma once

#include "Cell.h"

class GameControl sealed
{
	static bool m_run;

	static float frequency;

	static float time_0_cycle;

public:

	static void Control();
	static void	Run();
	static void Stop();
	static void Clear();

	static bool IsRun();
};
