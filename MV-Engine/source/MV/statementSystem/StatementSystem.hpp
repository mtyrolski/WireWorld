#pragma once

#include <chrono>
#include <vector>

#include <SFML/Graphics/Font.hpp>

#include "MV/logger/Logger.hpp"
#include "MV/statementSystem/Statement.hpp"
#include "MV//ticker/Ticker.hpp"


namespace mv
{
	class StatementSystem final : public Ticker
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		static StatementSystem *instance;

		sf::Font font;
		std::vector<Statement> statements;

		/* ===Methods=== */
	public:
		static void createInstance();
		static StatementSystem& getInstance();

		std::vector<Statement>& getStatements();

		void tick() override;

		void addStatement(const std::string& _text, float time);
	protected:
	private:
		StatementSystem();
		~StatementSystem();
		StatementSystem(StatementSystem const& copy) = delete;            // Not Implemented
		StatementSystem& operator=(StatementSystem const& copy) = delete; // Not Implemented
	};
}