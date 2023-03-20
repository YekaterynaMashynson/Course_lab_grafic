#pragma once
#include "Figure.h"
#include <sstream>
#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Line:public Figure
{
	RectangleShape line;
	float length=0;
	float width=0;
public:
	Line(); 
	Line(float length, float width, Color color);
	void draw(RenderWindow& window)override;
	void set_color(Color color)override;
	void move(float x, float y) override;
	Figure* clone() override;
	const string serialize()override;
	void set_as_active()override;
	void set_as_unactive()override;
	float check_x(float x, float width);
	float check_y(float y, float height);
	void set_size()override;
	float get_x()override;
	float get_y()override;
	static Line* deserialize(string obj_inf);
};

