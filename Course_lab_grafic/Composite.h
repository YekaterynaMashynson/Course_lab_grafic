#pragma once
#include "SFML/Graphics.hpp"
#include "Figure.h"
using namespace std;
using namespace sf;
class Composite:public Figure
{
	//realisation of pattern composite
private:
	vector<Figure*> composite_figure;
public:
	Composite();
	~Composite();
	void draw(RenderWindow& window)override;
	void move(float x, float y) override;
	void set_color(Color color)override;
	void set_as_active()override;
	void set_as_unactive()override;
	void add_figure(Figure* figure);
};

