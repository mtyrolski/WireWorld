#include "Statement.hpp"

namespace mv
{
	Statement::Statement(const std::string & _text, float _time, sf::Font &font, std::vector<Statement>& statements)
		:liveTime(_time)
	{
		text.setString(_text);
		text.setFont(font);
		text.setScale(sf::Vector2f(0.5,0.5));

		text.move(sf::Vector2f(0, statements.size()*text.getGlobalBounds().height));

		createdTime = clock();
	}

	bool Statement::isActive()
	{
		return (clock()-createdTime)/CLOCKS_PER_SEC < liveTime;
	}

	void Statement::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(text, states);
	}
}