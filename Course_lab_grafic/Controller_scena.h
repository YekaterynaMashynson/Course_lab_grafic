#pragma once
#include <SFML/Graphics.hpp>
#include "Keyboard_flag.h"
#include "Figure.h"

using namespace sf;
class Controller_scena
{

private:
	
	//making private constructor for Singletone
	Controller_scena(){}
	~Controller_scena() {}
	Controller_scena& operator=(Controller_scena&)=delete;
	Controller_scena(Controller_scena const&) = delete;
	Keyboard_flag flags;
	vector<Figure*> container;
public:
	//Singletone
	static Controller_scena& get_controler();
	//other functions of the controller
	

	void handle_key_pressed(Event& event, RenderWindow& window);

	void handle_key_released(Event& event);

	void handle_drawing_mode(RenderWindow& window);

	void handle_events(Event& event, RenderWindow& window);

	void handle_keyboard_actions(RenderWindow& window /*,*/ /*FigureContainer* container, MementoList* mementos*/);

	void print_menu();
	///
	void draw_figures(RenderWindow& window);
	////
	void add_from_concole();


};
