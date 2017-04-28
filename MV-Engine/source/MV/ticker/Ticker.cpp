#include "Ticker.hpp"

namespace mv
{
	 std::vector<Ticker*> Ticker::objects;

	Ticker::Ticker(Ticker * pointer)
	{
		objects.push_back(pointer);
	}

	Ticker::~Ticker()
	{
		removePointer(this);
	}

	void Ticker::tickLoop()
	{
		for (auto&var : objects)
		{
			var->tick();
		}
	}

	void Ticker::removePointer(Ticker * ptr)
	{
		for (auto itr = objects.begin(); itr != objects.end(); ++itr)
		{
			if (*itr = ptr)
			{
				objects.erase(itr);
				return;
			}
		}
	}
}
