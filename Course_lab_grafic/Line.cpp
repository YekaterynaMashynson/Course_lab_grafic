#include "Line.h"
using namespace std;

Line::Line()
{
	line = RectangleShape(Vector2f(190, 4));
	this->length = 190;
	this->width = 4;
	this->color = Color::Green;
	line.setFillColor(Color::Green);
}

Line::Line(float length, float width, Color color)
{
	this->length = length;
	this->width = width;
	this->color = color;
	line = RectangleShape(Vector2f(length, width));
	line.setFillColor(color);
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

const string Line::serialize()
{
	stringstream str;
	str << '('<<"2" << ' '
		<< is_active << ' '
		<< length << ' '
		<< width << ' '
		<< color.toInteger() << ' '
		<< get_x() << ' '
		<< get_y() <<')';
	return str.str();
}

void Line::set_as_active()
{
	line.setOutlineThickness(1);
	line.setOutlineColor(Color::Red);
	is_active = true;
}

void Line::set_as_unactive()
{
	line.setOutlineColor(Color::Transparent);
	is_active = false;
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

void Line::set_size()
{
	float new_length;
	float new_width;
	cout << "Enter line length = ";
	cin >> new_length;
	cout << "Enter line thickness = ";
	cin >> new_width;
	line.setSize(Vector2f(new_length, new_width));
	length = new_length;
	width = new_width;

}

float Line::get_x()
{
	return area_x;
}

float Line::get_y()
{
	return area_y;
}

bool Line::activated()
{
	return is_active;
}

Line* Line::deserialize(string obj_inf)
{
	stringstream str;
	str << obj_inf;
	bool active;
	float pos_x;
	float pos_y;
	float lenth;
	float width;
	Uint32 color;
	str >> active >> lenth>>width >> color >> pos_x >> pos_y;
	Line* des_line = new Line(lenth,width,Color(color));
	des_line->area_x = pos_x;
	des_line->area_y = pos_y;
	des_line->line.setPosition(pos_x, pos_y);
	if (active) 
	{
		des_line->set_as_active();
	}
	else 
	{
		des_line->set_as_unactive();
	}
	return des_line;
}
