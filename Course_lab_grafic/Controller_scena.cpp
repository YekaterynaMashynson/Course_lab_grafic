#include "Controller_scena.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Composite.h"
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

	case sf::Keyboard::A:		flags.unite_in_agregate = false; break;
		//add
	/*case sf::Keyboard::Num0:     flags.add_flag = false; break;
	case sf::Keyboard::Num5:    flags.drawing_mode_on = false; break;*/
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
		///

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
	case sf::Keyboard::Num5:    flags.create_prototype = true; break;
		//load state
	case sf::Keyboard::Num7:    flags.load_key_pressed = true; break;

	case sf::Keyboard::A:		flags.unite_in_agregate = true; break;
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
		flags.add_flag = false;
	}
	if (!is_empty()) 
	{
		//изменить клонирование фигуры
		if (flags.left_flag)
			container[curr_figure]->move(-SMOOTH_DISTANCE, 0);
		if (flags.right_flag)
			container[curr_figure]->move(SMOOTH_DISTANCE, 0);
		if (flags.up_flag)
			container[curr_figure]->move(0, -SMOOTH_DISTANCE);
		if (flags.down_flag)
			container[curr_figure]->move(0, SMOOTH_DISTANCE);

		if (flags.create_prototype)
		{
			create_prototype_of_active_figure();
			flags.create_prototype = false;
		}

		if (flags.change_size_flag) 
		{
			set_size_from_console();
			flags.change_size_flag = false;
		}
			
		if (flags.create_multiple_shape_flag) 
		{
			create_agregate();
			flags.create_multiple_shape_flag = false;
		}
		if (flags.change_color_flag) 
		{
			set_color_from_console();
			flags.change_color_flag = false;
		}
		draw_figures(window);
	}
	
}

void Controller_scena::print_menu() 
{
	cout << "Up, Down, Left, Right - arrows\n"
		<< "Add figure - 0\n"
		<< "Change active figure - 1\n"
		<< "Unite shapes - 2\n"
		<< "Change size - 3\n"
		<< "Change color - 4\n"
		<< "Clone active figure - 5\n"
		<< "Drawing Mode Off - 6\n"
		<< "Load previous state - 7\n";
}

void Controller_scena::draw_figures(RenderWindow& window)
{
	window.clear(Color::White);
	for (auto& shape : container) 
	{
		shape->draw(window);
	}
}

void Controller_scena::add_from_concole()
{
	cout << "0 - Circle\n"
		<< "1 - Rectangle\n"
		<< "2 - Line\n"
		<< "Choose the figure u want to add: ";
	int choice;
	cin >> choice;
	Figure* new_figure;
	switch (choice) 
	{
		//add posipility to chose color and size from concole
	case 0: new_figure = new Circle(); break;
	case 1:new_figure = new Rectangle(); break;
	case 2: new_figure = new Line(); break;
	default:
		cout << "Incorrect figure";
		break;
	}
	container.push_back(new_figure);
	curr_figure = container.size() - 1;
	container[curr_figure]->set_as_active();
	if (container.size() > 1) {
		container[curr_figure - 1]->set_as_unactive();
	}
	//function - set as an active and current selected
	cout << "--------------------------" << endl;
}

bool Controller_scena::is_empty()
{
	return container.size() < 1;
}

void Controller_scena::set_color_from_console()
{
	cout << "0 - Black\n1 - Cyan\n2 - Yellow\n3 - Green\n4 - Blue\nChoose color: ";

	int color_choice;
	cin >> color_choice;

	Color color;
	switch (color_choice)
	{
	case 0: color =  Color(Color::Black); break;
	case 1: color = Color(Color::Cyan); break;
	case 2: color =  Color(Color::Yellow); break;
	case 3: color = Color(Color::Green); break;
	case 4: color = Color(Color::Blue); break;
	default:
		color =  Color(Color::Black); break;
	}
	container[curr_figure]->set_color(color);

}

void Controller_scena::set_size_from_console()
{
	container[curr_figure]->set_size();
}

void Controller_scena::create_prototype_of_active_figure()
{
	Figure* clone_figure = container[curr_figure]->clone();
	container.push_back(clone_figure);
	container[curr_figure]->set_as_unactive();
	curr_figure = container.size() - 1;
	container[curr_figure]->set_as_active();
	cout << "--------------------------" << endl;
}

void Controller_scena::create_agregate()
{
	Composite* new_comp = new Composite();
	for (auto& shape : container)
	{
		new_comp->add_figure(shape);
	}
	container.erase(container.begin(), container.end());
	container.push_back(new_comp);
	curr_figure = container.size() - 1;
	container[curr_figure]->set_as_active();
}
