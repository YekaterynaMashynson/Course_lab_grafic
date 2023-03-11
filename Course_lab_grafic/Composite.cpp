#include "Composite.h"

Composite::Composite()
{
	composite_figure = vector<Figure*>();
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
	for (auto& shape : composite_figure)
	{
		shape->set_as_active();
	}
}

void Composite::set_as_unactive()
{
	for (auto& shape : composite_figure)
	{
		shape->set_as_unactive();
	}
}

void Composite::add_figure(Figure* figure)
{
	composite_figure.push_back(figure);
}

