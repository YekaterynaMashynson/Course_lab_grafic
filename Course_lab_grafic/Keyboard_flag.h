#pragma once
struct Keyboard_flag {
public:
	bool up_flag = false;
	bool right_flag = false;
	bool down_flag = false;
	bool left_flag = false;

	bool add_flag = false; //0

	bool switch_next_key_pressed = false; //1
	bool switched = false;

	bool create_multiple_shape_flag = false; //2
	bool change_size_flag = false; //3
	bool change_color_flag = false; //4

	bool drawing_mode_on = false; //5 on //6 off

	bool previous_state_loaded = false; //7
	bool load_key_pressed = false;
};