#include "Rectangle.h"

Rectangle::Rectangle()
{
	rectangle = RectangleShape(Vector2f(100, 50));
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
}

Figure* Rectangle::clone()
{
	return new Rectangle(*this);
}
 