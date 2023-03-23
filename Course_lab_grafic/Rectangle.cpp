#include "Rectangle.h"

using namespace std;
Rectangle::Rectangle()
{
	rectangle = RectangleShape(Vector2f(170, 100));
	this->width = 170;
	this->height = 100;
	this->color = Color::Magenta;
	rectangle.setFillColor(color);
}

Rectangle::Rectangle(float width, float height, Color color)
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

const string Rectangle::serialize()
{
	stringstream str;
	str <<'('<<"1" << ' '
		<< is_active << ' '
		<< width << ' '
		<< height << ' '
		<< color.toInteger() << ' '
		<< get_x() << ' '
		<< get_y() <<')';
	return str.str();
}

void Rectangle::set_as_active()
{
	is_active = true;
	rectangle.setOutlineThickness(4);
	rectangle.setOutlineColor(Color::Red);
}

void Rectangle::set_as_unactive()
{
	is_active = false;
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

void Rectangle::set_size()
{
	float new_height;
	float new_width;
	cout << "Enter rectangle width = ";
	cin >> new_width;
	cout << "Enter rectangle height = ";
	cin >> new_height;
	rectangle.setSize(Vector2f(new_width, new_height));
	height = new_height;
	width = new_width;
}

float Rectangle::get_x()
{
	return area_x;
}

float Rectangle::get_y()
{
	return area_y;
}

bool Rectangle::activated()
{
	return is_active;
}

Rectangle* Rectangle::deserialize(string obj_inf)
{
	//cout << "object string info" << obj_inf << endl;
	stringstream str;
	str << obj_inf;
	bool active;
	float pos_x;
	float pos_y;
	float width;
	float height;
	Uint32 color;
	str >> active >> width >> height >> color >> pos_x >> pos_y;
	Rectangle* des_rectangle = new Rectangle(width, height, Color(color));
	des_rectangle->area_x = pos_x;
	des_rectangle->area_y = pos_y;
	des_rectangle->rectangle.setPosition(pos_x, pos_y);
	if (active) 
	{
		des_rectangle->set_as_active();
	}
	else 
	{
		des_rectangle->set_as_unactive();
	}
	return des_rectangle;
}
