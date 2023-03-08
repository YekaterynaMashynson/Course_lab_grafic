#pragma once
#include "Figure.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class Circle:public Figure
{
protected:
	CircleShape circle;
public:
	Circle();
	Circle(float radius, Color color);
	void draw(RenderWindow& window)override;
	void set_color(Color color)override;
	void move(float x, float y) override;
	Figure* clone() override;
	void set_as_active()override;
	void set_as_unactive()override;
};

