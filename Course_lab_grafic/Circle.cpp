#include "Circle.h"
//default circle
Circle::Circle()
{
	circle = CircleShape(100.0f);
	this->color = Color::Cyan;
	this->radius = 100.0f;
	circle.setFillColor(color);
}
//from console
Circle::Circle(float radius, Color color)
{
	circle = CircleShape(radius);
	this->radius = radius;
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
	area_x = check_x(area_x + x,radius*2);
	area_y = check_y(area_y + y,radius*2);
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

float Circle::check_x(float x, float width)
{
	if (x < 0 - width) return 750;
	if (x > 750) return 0-width;
	return x;
}

float Circle::check_y(float y, float height)
{
	if (y < 0 - height) return 500;
	if (y > 500) return 0-height;
	return y;
}
