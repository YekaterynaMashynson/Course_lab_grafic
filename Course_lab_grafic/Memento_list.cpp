#include "Memento_list.h"

Memento_list::Memento_list()
{
	file_names = vector<string>();
}

Memento_list::~Memento_list()
{
	for (int i = 0; i < file_names.size(); i++)
	{
		remove(file_names[i].c_str());
	}
}

void Memento_list::save_new_memo(string memo)
{
	string new_file_name = "memento" + to_string(file_names.size()) + ".txt";
	file_names.push_back(new_file_name);
	ofstream new_memo(new_file_name);
	if (new_memo.is_open()) 
	{
		for (int i = 0; i < file_names.size(); i++) 
		{
			cout << file_names[i] << endl;
		}
		new_memo << memo;
	}
	new_memo.close();
}

stringstream Memento_list::load_last_memo()
{
	stringstream stream;
	if (!file_names.empty()) 
	{
		ifstream last_memo(file_names.back());
		if (last_memo.is_open()) 
		{
			stream << last_memo.rdbuf();
		}
		remove(file_names.back().c_str());
		file_names.pop_back();
	}
	return stream;
}
