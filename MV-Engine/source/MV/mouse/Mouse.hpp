#pragma once

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Window/Mouse.hpp"

#include "MV/scene/Scene.hpp"
#include "MV//ticker/Ticker.hpp"
#include "MV/resourceCache/Cache.hpp"
#include "MV/math/Math.hpp"

namespace mv
{
	class Mouse : public sf::Drawable, public Ticker
	{
		/* ===Objects=== */
	public:
		enum class TYPE
		{
			MV_DEFAULT = 0,
			SYSTEM_DEFAULT = 1,
		};
	protected:
	private:
		sf::Sprite object;

		//to checking border
		sf::Vector2u tolerance;
 
		bool movingPermission;
		mv::Cache<sf::Texture> cache;

		static Mouse *instance;

		/* ===Methods=== */
	public:
		static Mouse& getInstance();

		static void createInstance(const Mouse::TYPE& type = Mouse::TYPE::MV_DEFAULT, bool movingBorderPermission = false);

		~Mouse();

		void changeType(const Mouse::TYPE& type);

		void setBorderMovingMode(bool mode);

		void setTolerance(sf::Vector2u value);
		void setTolerance(unsigned long value_x, unsigned long value_y);

		void changeScale(float change);

		void tick() override;

	protected:
	private:
		Mouse(const Mouse::TYPE& type = Mouse::TYPE::MV_DEFAULT, bool movingBorderPermission = false);
		Mouse() = delete;  // Not Implemented
		Mouse(Mouse const& copy) = delete;            // Not Implemented
		Mouse& operator=(Mouse const& copy) = delete; // Not Implemented

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void positionUpdate();
		void checkBorders();
		void checkClick();
	};
}
