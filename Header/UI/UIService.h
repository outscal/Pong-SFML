#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class UIService {
private:
	Font font;
	Text left_score_text;
	Text right_score_text;

	std::string texture_path = "Assets/Fonts/AmberyGardenRegular-PKjGd.ttf";


	int font_size = 40;
	Color font_color = Color::White;
	std::string initial_string = "00";

	float left_score_position_x = 570.0f;
	float left_score_position_y = 30.0f;

	float right_score_position_x = 670.0f;
	float right_score_position_y = 30.0f;

	int player1_score = 0;
	int player2_score = 0;


public:
	void loadFontTexture();
	void createLeftScoreText();
	void createRightScoreText();
	std::string formatScore(int score);
	void incrementPlayer1Score();
	void incrementPlayer2Score();
	void update();
	void render(RenderWindow* game_window);
};
