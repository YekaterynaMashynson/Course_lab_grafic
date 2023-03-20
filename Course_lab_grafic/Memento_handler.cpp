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

void Memento_handler::load(vector<Figure*>& new_contr, Memento_list*mementos)
{
	new_contr.clear();
	stringstream obj_inf = mementos->load_last_memo();
	string shape_inf;
	while (getline(obj_inf, shape_inf)) 
	{
		if (shape_inf[0] == '{') 
		{
			cout << "Creating agregate ";
			new_contr.push_back(Composite::deserialize(shape_inf));
		}
		else if(shape_inf[0] == '(')
		{
			string str = shape_inf.substr(3, shape_inf.find_first_of(')'));

			switch (shape_inf[1])
			{
			case '0':
				cout << "Creating circle";
			    new_contr.push_back(Circle::deserialize(str));break;  
			case '1':
				cout << "Creating rectangle";
			    new_contr.push_back(Rectangle::deserialize(str));break;
			case '2':
				cout << "Creating line";
				new_contr.push_back(Line::deserialize(str));break;
			default:
				break;
			}
		}
	}

}
