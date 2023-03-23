#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace sf;
using namespace std;
class Figure
{  
protected:
	Color color;
	float area_x = 0;
	float area_y = 0;
	bool is_active = false;
public:
	virtual void draw(RenderWindow& window) = 0;
	virtual void move(float x, float y) = 0;
	virtual void set_color(Color color) = 0;
	virtual void set_size() = 0;
	virtual float get_x() = 0;
	virtual float get_y() = 0;
	virtual const string serialize() = 0;
	// Figure cloning ( Prototype)
	virtual Figure* clone() = 0;
	/// 
	virtual bool activated() = 0;
	virtual void set_as_active() = 0;
	virtual void set_as_unactive() = 0;
};

