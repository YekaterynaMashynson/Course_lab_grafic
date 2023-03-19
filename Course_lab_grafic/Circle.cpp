#include "Circle.h"


Circle::Circle()
{
	circle = CircleShape(50.0f);
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
	circle.setOutlineThickness(4);
	circle.setOutlineColor(Color::Red);
	is_active = true;
}

void Circle::set_as_unactive()
{
	circle.setOutlineColor(color);
	is_active = false;
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

void Circle::set_size()
{
	float new_radius;
	cout << "Enter radius = ";
	cin >> new_radius;
	circle.setRadius(new_radius);
	radius = circle.getRadius();
	/*circle.setScale(2,2);*//*setScale(circle.getScale() + sf::Vector2f(0.0001f, 0.0001f));*/
}

float Circle::get_x()
{
	return area_x;
}

float Circle::get_y()
{
	return area_y;
}

//const string Circle::str_info()
//{
//	stringstream str;
//		str << "* " << "Circle"<<' '
//				<<is_active<<' '
//				<<color.toInteger()<<' '
//				<<radius<<' '
//				<<get_x()<<' '
//				<<get_y()<<' ';
//			return str.str();
//}

const string Circle::serialize()
{
	stringstream str;
	str <<'(' << "Circle:" << ' '
		<<is_active<<' '
		<<radius<<' '
		<< color.toInteger()<<' '
		<<get_x()<<' '
		<<get_y()<<')';
	return str.str();
}
