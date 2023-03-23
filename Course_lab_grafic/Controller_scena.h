#pragma once
#include <SFML/Graphics.hpp>
#include "Keyboard_flag.h"
#include "Memento_list.h"
#include "Figure.h"

using namespace sf;
using namespace std;
const float SMOOTH_DISTANCE = 0.1;
class Controller_scena
{
private:
	//making private constructor for Singletone
	Controller_scena(){}
	~Controller_scena() 
	{
		delete container_memento;
		for (int index = 0; index < container.size(); ++index)
		{
			delete container[index];
		}
	}
	Controller_scena& operator=(Controller_scena&)=delete;
	Controller_scena(Controller_scena const&) = delete;
	Keyboard_flag flags;
	vector<Figure*> container;
	Memento_list* container_memento = new Memento_list();
	int curr_figure = -1;
public:
	//Singletone
	static Controller_scena& get_controler();
	//other functions of the controller

	////
	void handle_key_pressed(Event& event, RenderWindow& window);
	////
	void handle_key_released(Event& event);
	////
	void handle_events(Event& event, RenderWindow& window);
	////
	void handle_keyboard_actions(RenderWindow& window);
	////
	void print_menu();
	///
	void draw_figures(RenderWindow& window);
	////
	void add_from_concole();
	//// 
	bool is_empty();
	///
	void set_color_from_console();
	///  
	void set_size_from_console();
	///
	void create_prototype_of_active_figure();
	////
	void create_agregate();
	////
	void switch_next();
};
