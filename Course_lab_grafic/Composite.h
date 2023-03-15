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
	Composite(vector<Figure*> agg);
	Composite(const Composite &obj);
	~Composite();
	void draw(RenderWindow& window)override;
	void move(float x, float y) override;
	void set_color(Color color)override;
	void set_as_active()override;
	void set_as_unactive()override;
	void add_figure(Figure* figure);
	Figure* clone()override;
	void set_size()override;
	float get_x()override;
	float get_y()override;
};

