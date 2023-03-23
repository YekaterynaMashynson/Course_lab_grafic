#pragma once
struct Keyboard_flag 
{
public:
	bool up_flag = false;
	bool right_flag = false;
	bool down_flag = false;
	bool left_flag = false;

	bool add_flag = false; //0
	bool switch_next_key_pressed = false; //1
	bool create_agregate_figure_flag = false; //2
	bool change_size_flag = false; //3
	bool change_color_flag = false; //4
	bool create_prototype = false; //5 
	bool load_key_pressed = false;//6
};