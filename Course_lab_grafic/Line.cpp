#include "Line.h"

Line::Line()
{
	line = RectangleShape(Vector2f(170, 4));
	this->length = 170;
	this->width = 4;
	line.setFillColor(Color::Magenta);
}

Line::Line(float length, float width, Color color)
{
	this->length = length;
	this->width = width;
	this->color = color;
}

void Line::draw(RenderWindow& window)
{
	window.draw(line);
}

void Line::set_color(Color color)
{
	this->color = color;
	line.setFillColor(color);
}

void Line::move(float x, float y)
{ 
	area_x = check_x(area_x + x, length);
	area_y = check_y(area_y + y, width);
	line.setPosition(area_x, area_y);
}

Figure* Line::clone()
{
	return new Line(*this);
}

void Line::set_as_active()
{
	line.setOutlineThickness(1);
	line.setOutlineColor(Color::Red);
}

void Line::set_as_unactive()
{
	line.setOutlineColor(Color::Transparent);
}

float Line::check_x(float x, float length)
{
	if (x < 0 -length ) return 750;
	if (x > 750) return 0 - length;
	return x;
}

float Line::check_y(float y, float width)
{
	if (y < 0 - width) return 500;
	if (y > 500) return 0 - width;
	return y;
}
