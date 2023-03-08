#include "Circle.h"
//default circle
Circle::Circle()
{
	circle = CircleShape(100.0f);
	this->color = Color::Cyan;
	circle.setFillColor(color);
}
//from console
Circle::Circle(float radius, Color color)
{
	circle = CircleShape(radius);
	this->color = color;
	circle.setFillColor(color);
}

void Circle::draw(RenderWindow& window)
{
	window.draw(circle);
}

void Circle::set_color(Color color)
{
	this->color = color;
	circle.setFillColor(color);
}

void Circle::move(float x, float y)
{
	area_x = area_x + x;
	area_y = area_y + y;
	circle.setPosition(area_x, area_y);
}

Figure* Circle::clone()
{
	return new Circle(*this);
}

void Circle::set_as_active()
{
	circle.setOutlineThickness(10);
	circle.setOutlineColor(Color::Red);
}

void Circle::set_as_unactive()
{
	circle.setOutlineColor(color);
}
