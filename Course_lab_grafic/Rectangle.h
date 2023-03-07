#pragma once
#include "Figure.h"
#include "SFML/Graphics.hpp"
using namespace sf;
class Rectangle:public Figure
{
private:
    float width;
    float height;
    RectangleShape rectangle;
public:
	Rectangle();
	Rectangle(float width,float hight, Color color);
	void draw(RenderWindow& window)override;
	void set_color(Color color)override;
	void move(float x, float y) override;
	Figure* clone() override;
};

