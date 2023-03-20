#pragma once
#include "Memento_list.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Figure.h"
#include "Composite.h"
using namespace std;
class Memento_handler
{
public:
	static void save(vector<Figure*>,Memento_list*);
	static void load(vector<Figure*>&, Memento_list*);
};

