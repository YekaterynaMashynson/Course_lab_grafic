#include "Rectangle.h"

Rectangle::Rectangle()
{
	rectangle = RectangleShape(Vector2f(170, 100));
	this->color = Color::Magenta;
	rectangle.setFillColor(color);
}

Rectangle::Rectangle(float width, float hight, Color color)
{
	this->color = color;
	rectangle =  RectangleShape(Vector2f(width, height));
	rectangle.setFillColor(color);
}

void Rectangle::draw(RenderWindow& window)
{
	window.draw(rectangle);
}

void Rectangle::set_color(Color color)
{
	this->color = color;
	rectangle.setFillColor(color);
}

void Rectangle::move(float x, float y)
{
	area_x = area_x + x;
	area_y = area_y + y;
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
 