#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
class Figure
{ 
protected:
	Color color;
	float area_x = 0;
	float area_y = 0;
public:
	virtual void draw(RenderWindow& window) = 0;
	virtual void move(float x, float y) = 0;
	virtual void set_color(Color color) = 0;
	// Figure cloning ( Prototype)
	virtual Figure* clone() = 0;
	/// 
	virtual void set_as_active() = 0;
	virtual void set_as_unactive() = 0;
};

