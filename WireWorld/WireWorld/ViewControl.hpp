#pragma once

#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Window.hpp"
#include "FPScontroller.hpp"


class ViewControl sealed
{
	static Window *m_window;
	
	static sf::View m_view;

	static float moveValue;
	static const float zoomValue;
	static const float reductionValue;

public:

	static enum
	{
		REDUCTION = -1,
		ZOOM = 1,

		TOP = 0,
		RIGHT = 1,
		DOWN = 2,
		LEFT = 3
	};

	static void Init(Window* window, sf::Vector2f windowDimensions, float moveSpeed);
	
	static void Zoom(short value);

	static void Move(short value);

	static void CheckKeyboard();
};
