#pragma once
#include <SFML/Graphics.hpp>
namespace Gameplay

{
	class Boundary
	{
	private:
		sf::RectangleShape topBoundary;
		sf::RectangleShape bottomBoundary;
		sf::RectangleShape leftBoundary;
		sf::RectangleShape rightBoundary;
		sf::RectangleShape centerLine;

		const float horizontal_boundary_width = 1280.0f;
		const float horizontal_boundary_height = 20.0f;

		const float top_position_x = 0.0f;
		const float top_position_y = 0.0f;

		const float bottom_position_x = 0.0f;
		const float bottom_position_y = 700.0f;

		const float vertical_boundary_width = 20.0f;
		const float vertical_boundary_height = 720.0f;

		const float left_position_x = 0.0f;
		const float left_position_y = 0.0f;

		const float right_position_x = 1260.0f;
		const float right_position_y = 0.0f;

		const float center_line_width = 10.0f;
		const float center_line_height = 680.0f;

		const float center_line_position_x = 640.0f;
		const float center_line_position_y = 20.0f;

		const sf::Color boundary_color = sf::Color::Blue;
		const sf::Color center_line_color = sf::Color::White;

		void createTopBoundary();
		void createBottomBoundary();
		void createLeftBoundary();
		void createRightBoundary();

		void createCenterLine();
	
	public:
		Boundary();
		void render(sf::RenderWindow*game_window);
		
	};
}