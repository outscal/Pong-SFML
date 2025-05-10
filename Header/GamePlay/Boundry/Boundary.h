#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace GamePlay {

	class Boundary {

	private:

		RectangleShape topBoundary, bottomBoundary;
		RectangleShape leftBoundary, rightBoundary;
		RectangleShape center_line;

		float horizontal_boundary_width = 1950.f, horizontal_boundary_height = 25;

		float vertical_boundary_width= 25.f, vertical_boundary_height= 970.f;

		float top_boundary_x_pos = 0.f, top_boundary_y_pos = 0.f;
		float bottom_boundary_X_pos = 0, bottom_boundary_y_Pos = 970;
		float left_boundary_x_pos = 3.f, left_boundary_y_pos = 0.f;
		float right_boundary_x_pos = 1885.f, right_boundary_y_pos = 0.f;
		float center_line_x_pos = 943.f, centre_line_y_pos = 0.f;

		const Color side_boundary_color = Color::Blue;
		const Color center_line_color = Color::White;

		float centerLineHeight = 680.f;
		float centerLineWidth = 10.f;



		void CreateTopBoundary();
		void CreateBottomBoundary();
		void CreateLeftBoundary();
		void CreateRightBoundary();
		void CreateCenterLine();
	public:

		Boundary();
		void Render(RenderWindow* game_window);



	};
}