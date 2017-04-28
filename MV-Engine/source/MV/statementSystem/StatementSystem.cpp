#include "StatementSystem.hpp"

namespace mv
{

	StatementSystem* StatementSystem::instance;

	StatementSystem::StatementSystem()
		:Ticker(this)
	{
	}

	StatementSystem::~StatementSystem()
	{
		Ticker::removePointer(this);
	}

	void StatementSystem::createInstance()
	{
		if (instance == 0)
		{
			instance = new StatementSystem();
			instance->font.loadFromFile("data/font/arial.ttf");
		}
		else
		{
			Logger::Log(constants::error::singleton::SINGLETON_INITED, Logger::STREAM::CONSOLE, Logger::TYPE::INFO);
		}
	}

	StatementSystem & StatementSystem::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

	std::vector<Statement>& StatementSystem::getStatements()
	{
		return statements;
	}

	void StatementSystem::tick()
	{
		for (auto itr = statements.begin(); itr != statements.end();)
		{
			if (!itr->isActive())
				itr = statements.erase(itr);
			else
				++itr;
		}
	}

	void StatementSystem::addStatement(const std::string & _text, float time)
	{
		statements.emplace_back(_text, time,font,statements);
	}
}
