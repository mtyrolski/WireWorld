#include "GameControl.h"

bool GameControl::m_run = false;
float GameControl::frequency = 2.0f;
float GameControl::time_0_cycle;


void GameControl::Control()
{
	if ((clock() - time_0_cycle) / CLOCKS_PER_SEC > frequency)
	{
		for (auto &var : Cell::cells)
		{
			var.Update();
		}
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
	for (auto &var : Cell::cells)
	{
		var.SetState(Cell::EMPTY);
	}
}

bool GameControl::IsRun()
{
	return m_run;
}
