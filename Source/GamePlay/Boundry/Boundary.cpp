#include "D:/unity/repos/SFML-Pong/Header/GamePlay/Boundry/Boundary.h"

namespace GamePlay {

	GamePlay::Boundary::Boundary()
	{
		CreateTopBoundary();
		CreateBottomBoundary();
		CreateLeftBoundary();
		CreateRightBoundary();
		CreateCenterLine();
	}

	void Boundary::CreateTopBoundary()
	{
		topBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		topBoundary.setFillColor(side_boundary_color);
		topBoundary.setPosition(top_boundary_x_pos, top_boundary_y_pos);
	}

	void Boundary::CreateBottomBoundary()
	{
		bottomBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		bottomBoundary.setPosition(Vector2f(bottom_boundary_X_pos, bottom_boundary_y_Pos));
		bottomBoundary.setFillColor(side_boundary_color);
	}

	void Boundary::CreateLeftBoundary()
	{
		leftBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		leftBoundary.setPosition(Vector2f(left_boundary_x_pos, left_boundary_y_pos));
		leftBoundary.setFillColor(side_boundary_color);
		
		
	}

	void Boundary::CreateRightBoundary()
	{
		rightBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		rightBoundary.setPosition(Vector2f(right_boundary_x_pos, right_boundary_y_pos));
		rightBoundary.setFillColor(side_boundary_color);
	}

	void Boundary::CreateCenterLine()
	{
		center_line.setSize(Vector2f(vertical_boundary_width / 2.5, vertical_boundary_height));
		center_line.setPosition(Vector2f(center_line_x_pos, centre_line_y_pos));
		center_line.setFillColor(Color::White);
	}
	

	void Boundary::Render(RenderWindow* game_window)
	{
		game_window->draw(topBoundary);
		game_window->draw(bottomBoundary);
		game_window->draw(leftBoundary);
		game_window->draw(rightBoundary);
		game_window->draw(center_line);
	}


}

