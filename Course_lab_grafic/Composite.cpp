#include "Composite.h"

Composite::Composite()
{
 	composite_figure = vector<Figure*>();
}

Composite::Composite(vector<Figure*> agg)
{
	for (auto& shape : agg) 
	{
		add_figure(shape);
	}
}

Composite::Composite(const Composite& obj)
{ 
	this->composite_figure = vector<Figure*>();
	for (auto& shape : obj.composite_figure)
	{
		add_figure(shape->clone());
	}
}

Composite::~Composite()
{
	for (int index = 0; index < composite_figure.size(); ++index)
	{
		delete composite_figure[index];
	}
}

void Composite::draw(RenderWindow& window)
{
	for (auto& shape : composite_figure)
	{
		shape->draw(window);
	}
}

void Composite::move(float x, float y)
{
	for (auto& shape : composite_figure)
	{
		shape->move(x, y);
	}
}

void Composite::set_color(Color color)
{
	for (auto& shape : composite_figure)
	{
		shape->set_color(color);
	}
}

void Composite::set_as_active()
{
	is_active = true;
	for (auto& shape : composite_figure)
	{
		shape->set_as_active();
	}
}

void Composite::set_as_unactive()
{
	is_active = false;
	for (auto& shape : composite_figure)
	{
		shape->set_as_unactive();
	}
}

const string Composite::serialize()
{
	stringstream str;
	str << "{"<<is_active;
	for (auto& shape : composite_figure) 
	{
		str << shape->serialize();
	}
	str << "}";
	return str.str();
}

void Composite::add_figure(Figure* figure)
{
	composite_figure.push_back(figure);
}

Figure* Composite::clone()
{
	return new Composite(*this); 
}

void Composite::set_size()
{
	for (auto& shape : composite_figure)
	{
		shape->set_size();
	}
}

float Composite::get_x()
{
	return area_x;
}

float Composite::get_y()
{
	return area_y;
}

Composite* Composite::deserialize(string &mementos)
{
	Composite* composite = new Composite(); 
	if (mementos[1] == '1')
	{
		composite->is_active = true;
	}
	else
	{
		composite->is_active = false;
	}
	mementos.erase(0, 2);
	while (mementos[0] != '}')
	{
		if (mementos[0] == '{')
		{
			composite->composite_figure.push_back(deserialize(mementos));
		}  
		if (mementos[0] == '(')
		{
			string str = mementos.substr(3, mementos.find_first_of(')'));
			switch (mementos[1])
			{
			case '0':
				mementos.erase(0, 2);    composite->composite_figure.push_back(Circle::deserialize(str));break;
			case '1':
				mementos.erase(0, 2);    composite->composite_figure.push_back(Rectangle::deserialize(str));break;
			case '2':
				mementos.erase(0, 2);    composite->composite_figure.push_back(Line::deserialize(str));break;
			default:
				break;
			}
			mementos.erase(0, mementos.find_first_of(')') + 1);
		}
	} mementos.erase(0, 1);
	return composite;
}

