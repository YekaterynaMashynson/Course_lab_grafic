#include "Controller_scena.h"
#include "Circle.h"
#include "Rectangle.h"
#include<iostream>
using namespace std;

Controller_scena& Controller_scena::get_controler()
{
	static Controller_scena controller;
	return  controller;
}

void Controller_scena::handle_key_released(Event& event)
{
	switch (event.key.code)
	{
		// Process the up, down, left and right keys
	case sf::Keyboard::Up:     flags.up_flag = false; break;
	case sf::Keyboard::Down:    flags.down_flag = false; break;
	case sf::Keyboard::Left:    flags.left_flag = false; break;
	case sf::Keyboard::Right:    flags.right_flag = false; break;

		//add
	case sf::Keyboard::Num0:     flags.add_flag = false; break;
		//switchNext
	case sf::Keyboard::Num1: 
	{
		flags.switch_next_key_pressed = false;
		flags.switched = false;
		break;
	}
	default: break;
		//create multiple shape
	case sf::Keyboard::Num2:     flags.create_multiple_shape_flag = false; break;
		//changeSize
	case sf::Keyboard::Num3:     flags.change_size_flag = false; break;
		//changeColor
	case sf::Keyboard::Num4:    flags.change_color_flag = false; break;
		//load state
	case sf::Keyboard::Num7: {
		flags.load_key_pressed = false;
		flags.previous_state_loaded = false;
		break;
	}
	}
}

void Controller_scena::handle_key_pressed(Event& event, RenderWindow& window)
{
	switch (event.key.code)
	{
		// If escape is pressed, close the application
	case  sf::Keyboard::Escape: window.close(); break;

		// Process the up, down, left and right keys
	case sf::Keyboard::Up:      flags.up_flag = true; break;
	case sf::Keyboard::Down:    flags.down_flag = true; break;
	case sf::Keyboard::Left:    flags.left_flag = true; break;
	case sf::Keyboard::Right:  flags.right_flag = true; break;

		//add
	case sf::Keyboard::Num0:    flags.add_flag = true; break;
		//switchNext
	case sf::Keyboard::Num1:   flags.switch_next_key_pressed = true; break;
		//create multiple shape
	case sf::Keyboard::Num2: {flags.create_multiple_shape_flag = true; break; }
						   //changeSize
	case sf::Keyboard::Num3:    flags.change_size_flag = true; break;
		//changeColor
	case sf::Keyboard::Num4:    flags.change_color_flag = true; break;
		//drawingMode on
	case sf::Keyboard::Num5:    flags.drawing_mode_on = true; break;
		//drawingMode off
	case sf::Keyboard::Num6:    flags.drawing_mode_on = false; break;
		//load state
	case sf::Keyboard::Num7:    flags.load_key_pressed = true; break;
	default: break;
	}
}

void Controller_scena::handle_drawing_mode(RenderWindow& window) 
{

}
void Controller_scena::handle_events(Event& event, RenderWindow& window) 
{
	switch (event.type)
	{
		//if cross is pressed
	case Event::Closed: {
		window.close();
		break;
	}
					  // If a key is pressed
	case Event::KeyPressed:
	{
		handle_key_pressed(event, window);
		break;
	}
	// If a key is released
	case Event::KeyReleased:
	{
		handle_key_released(event);
		break;
	}
	default:
		break;
	}
}
void Controller_scena::handle_keyboard_actions(RenderWindow& window /*,*/ /*FigureContainer* container, MementoList* mementos*/) 
{
	if (flags.add_flag) 
	{
		add_from_concole();
	}
	draw_figures(window);
}
void Controller_scena::print_menu() 
{
	cout << "Up, Down, Left, Right - arrows\n"
		<< "Add figure - 0\n"
		<< "Change active figure - 1\n"
		<< "Unite shapes - 2\n"
		<< "Change size - 3\n"
		<< "Change color - 4\n"
		<< "Drawing Mode On - 5\n"
		<< "Drawing Mode Off - 6\n"
		<< "Load previous state - 7\n";
}

void Controller_scena::draw_figures(RenderWindow& window)
{
	for (auto& shape : container) 
	{
		shape->draw(window);
	}
}

void Controller_scena::add_from_concole()
{
	cout << "0 - Circle\n"
		<< "1 - Rectangle\n"
		<< "2 - Rhombus\n"
		<< "Choose the figure u want to add: ";
	int choice;
	cin >> choice;
	Figure* new_figure;
	switch (choice) 
	{
		//add posipility to chose color and size from concole
	case 0: new_figure = new Circle(); break;
	case 1:new_figure = new Rectangle(); break;
	default:
		cout << "Incorrect figure";
		break;
	}
	container.push_back(new_figure);
	//function - set as an active and current selected
	cout << "--------------------------" << endl;
}
