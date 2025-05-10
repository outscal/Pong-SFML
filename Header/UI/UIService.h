#pragma once

#include<iostream>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class UIService
{
private:
	Font font;
	Text right_score_text;
	Text left_score_text;
	string font_path = "Assets/Fonts/Aloevera-OVoWO.ttf";

	int font_size = 40;
	Color font_color = Color::White;
	string initial_score = "00";

	float left_score_pos_x = 570.f;
	float left_score_pos_y = 30.f;
	float right_score_pos_x = 670.f;
	float right_score_pos_y = 30.f;

	int player1_score = 0;
	int player2_score = 0;

	void loadFontTexture();
	void createLeftScoreText();
	void createRightScoreText();
	string formatScoreText(int score);
public:
	UIService();
	void render(RenderWindow* game_window);
	void update();
	void incrementPlayer1Score();
	void incrementPlayer2Score();
};

