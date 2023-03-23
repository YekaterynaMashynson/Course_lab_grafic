// Course_lab_grafic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"SFML/Graphics.hpp"
#include"Controller_scena.h"
#include <Windows.h>


using namespace sf;
int main()
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 100, 100, 400, 600, SWP_NOZORDER | SWP_NOACTIVATE);
    RenderWindow window(VideoMode(750, 500), "Mashynson course work");
	Controller_scena& contr = Controller_scena::get_controler();
	contr.print_menu();

	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			contr.handle_events(ev, window);
		}
		contr.handle_keyboard_actions(window);

		window.display();
	}
	return 0;
  
}

