#include "GameControl.hpp"

bool GameControl::m_run = false;
float GameControl::frequency = 0.25f;
float GameControl::time_0_cycle;


void GameControl::Control()
{
	if ((clock() - time_0_cycle) / CLOCKS_PER_SEC > frequency)
	{
		for (auto &var : Cell::cells)
			var.PrepareUpdate();

		for (auto &var : Cell::cells)
			var.ConfirmUpdate();

		time_0_cycle = clock();
	}
	
}

void GameControl::Run()
{
	GameControl::time_0_cycle = clock();
	GameControl::m_run = true;
}

void GameControl::Stop()
{
	GameControl::m_run = false;
}

void GameControl::Clear()
{
	GameControl::Stop();

	for (auto &var : Cell::cells)
		var.Clear();
}

bool GameControl::IsRun()
{
	return m_run;
}
