#pragma once 
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class Memento_list
{
private:
	vector<string> file_names;
public:
	Memento_list();
	~Memento_list();
	void save_new_memo(string);
	stringstream load_last_memo();
};

