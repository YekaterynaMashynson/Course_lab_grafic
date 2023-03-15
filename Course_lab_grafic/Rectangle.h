#pragma once
#include "Figure.h"
#include "SFML/Graphics.hpp"
using namespace sf;
class Rectangle:public Figure
{
private:
    float width=0;
    float height=0;
    RectangleShape rectangle;
public:
	Rectangle();
	Rectangle(float width,float hight, Color color);
	void draw(RenderWindow& window)override;
	void set_color(Color color)override;
	void move(float x, float y) override;
	Figure* clone() override;
	void set_as_active()override;
	void set_as_unactive()override;
	float check_x(float x, float width);
	float check_y(float y, float height);
	void set_size()override;
	float get_x()override;
	float get_y()override;
};

