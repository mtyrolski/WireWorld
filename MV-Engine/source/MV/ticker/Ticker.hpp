#pragma once

#include <vector>
#include <memory>

namespace mv
{
	class Ticker
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		static std::vector<Ticker*> objects;
		/* ===Methods=== */
	public:
		Ticker(Ticker* pointer);
		virtual ~Ticker();

		virtual void tick() = 0;

		static void tickLoop();

		static void removePointer(Ticker* ptr);
	protected:
	private:
	};
}
