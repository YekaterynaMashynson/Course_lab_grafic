#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include"Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace sf;
using namespace std;
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
	const string serialize()override;
	void add_figure(Figure* figure);
	Figure* clone()override;
	void set_size()override;
	float get_x()override;
	float get_y()override;
	static Composite* deserialize(string& mementos);
};

