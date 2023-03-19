#include "Memento_handler.h"

void Memento_handler::save(vector<Figure*> old_container, Memento_list*mementos)
{
	stringstream str;
	string my_str;
	for (auto& shape : old_container) 
	{
		str << shape->serialize() << endl;
	}
	my_str = str.str();
	cout << my_str;
	mementos->save_new_memo(my_str);
}
