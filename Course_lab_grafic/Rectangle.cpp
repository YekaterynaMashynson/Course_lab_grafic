#include "Rectangle.h"

Rectangle::Rectangle()
{
	rectangle = RectangleShape(Vector2f(170, 100));
	this->width = 170;
	this->height = 100;
	this->color = Color::Magenta;
	rectangle.setFillColor(color);
}

Rectangle::Rectangle(float width, float hight, Color color)
{
	this->width = width;
	this->height = height;
	this->color = color;
	rectangle =  RectangleShape(Vector2f(width, height));
	rectangle.setFillColor(color);
}

void Rectangle::draw(RenderWindow& window)
{
	/*window.clear(Color::White);*/
	window.draw(rectangle);
}

void Rectangle::set_color(Color color)
{
	this->color = color;
	rectangle.setFillColor(color);
}

void Rectangle::move(float x, float y)
{
	area_x = check_x(area_x + x,width);
	area_y = check_y(area_y + y,height);
	rectangle.setPosition(area_x, area_y);
}

Figure* Rectangle::clone()
{
	return new Rectangle(*this);
}

void Rectangle::set_as_active()
{
	rectangle.setOutlineThickness(4);
	rectangle.setOutlineColor(Color::Red);
}

void Rectangle::set_as_unactive()
{
	rectangle.setOutlineColor(Color::Transparent);
}

float Rectangle::check_x(float x, float width)
{
	if (x < 0 - width) return 750;
	if (x > 750) return 0 - width;
	return x;
}

float Rectangle::check_y(float y, float height)
{
	if (y < 0 - height) return 500;
	if (y > 500) return 0 - height;
	return y;
}
 