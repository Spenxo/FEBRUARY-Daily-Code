#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <windows.h>
#include <stdio.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5/allegro_image.h>
using namespace std;


int collision(int b1x, int b1y, int b1w, int b1h, int b2x, int b2y, int b2w, int b2h, int bouncer_dx, int bouncer_dy);
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *square2 = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *midwall = NULL;
	ALLEGRO_FONT *font = NULL;
	cout << "flag1" << endl;
	ALLEGRO_SAMPLE *sample3 = NULL;
	ALLEGRO_SAMPLE_INSTANCE *instance3 = NULL;
	ALLEGRO_BITMAP *ball = NULL;
	ALLEGRO_BITMAP *BGpic = NULL; 

	//these two variables hold the x and y positions of the square
	//initalize these variables to where you want your square to start
	float square_x = 0;
	float square_y = 40;

	float square2_x = 610;
	float square2_y = 40;

	float bouncer_x = 480/2;
	float bouncer_y = 640/2;

	int squarescore = 0;
	int square2score = 0;

	cout << "flag2" << endl;
	//here's our key states. they're all starting as "false" because nothing has been pressed yet.
	//the first slot represents "up", then "down", "left" and "right"
	bool key2[4] = { false, false, false, false };
	bool key[4] = { false, false, false, false };
	float bouncer_dx = -10, bouncer_dy = 10;
	
	//don't redraw until an event happens
	bool redraw = true;

	//this controls our game loop
	bool doexit = false;

	al_init();
	cout << "flag3" << endl;
	//get the keyboard ready to use
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	
	al_init_image_addon();
	
	al_install_audio();
	al_init_acodec_addon();
	
	timer = al_create_timer(.02);

	display = al_create_display(640, 480);

	font = al_load_ttf_font("Pong.ttf", 100, 0);
	cout << "flag4" << endl;
	sample3 = al_load_sample("BGmusic.wav");
    al_reserve_samples(10);
	midwall = al_create_bitmap(30, 640);
	square = al_create_bitmap(32, 128);
	square2 = al_create_bitmap(32, 128);
	bouncer = al_create_bitmap(42, 42);
	ball = al_create_bitmap(42, 42);
	BGpic = al_create_bitmap(640, 480);

	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(0, 0, 255));

	al_set_target_bitmap(square2);
	al_clear_to_color(al_map_rgb(255, 0, 0));

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(midwall);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	cout << "flag5" << endl;
	//these lines tell teh event source what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//new! tell the event queue that it should take keyboard events, too 
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	instance3 = al_create_sample_instance(sample3);
	al_set_sample_instance_playmode(instance3, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(instance3, al_get_default_mixer());

	al_flip_display();

	al_start_timer(timer);
	cout << "flag6" << endl;
	//so the game loop is set to act on "ticks" of the timer OR keyboard presses 
	//OR the mouse closing the display

	while (!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the movement algorithm

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//if the box hits the left wall OR the right wall
			if (bouncer_x < 0 || bouncer_x > 640 - 42) {
				//flip the x direction
				bouncer_dx = -bouncer_dx;
			}
			//if the box hits the top wall OR the bottom wall
			if (bouncer_y < 0 || bouncer_y > 480 - 42) {
				//flip the y direction
				bouncer_dy = -bouncer_dy;
			}

			if (bouncer_x < 0 && bouncer_y >= 0 && bouncer_y <= 480) {
				square2score = square2score + 1;
			}
			
			if (bouncer_x >= 600 && bouncer_y >= 0 && bouncer_y <= 480) {
				squarescore = squarescore + 1;
			}


			//really important code!
			//move the box in a diagonal
			bouncer_x += bouncer_dx;
			bouncer_y -= bouncer_dy;

			//redraw at every tick of the timer
			redraw = true;
		}
		cout << "flag7" << endl;
		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key2[0] && square2_y >= 0) {
				square2_y -= 8.0;
			}

			if (key2[1] && square2_y <= 480 - 128) {
				square2_y += 8.0;
			}

			//square2_y = bouncer_y - 64;
			
			if (key[0] && square_y >= 0) {
				square_y -= 8.0;
			}

			if (key[1] && square_y <= 480 - 128) {
				square_y += 8.0;
			}
			cout << "flag8" << endl;
			if (collision(bouncer_x, bouncer_y, 42, 42, square_x, square_y, 32, 128, bouncer_dx, bouncer_dy) == 1) {
			bouncer_dx = -bouncer_dx;
			PlaySound(TEXT("PongBounce.wav"), NULL, SND_FILENAME | SND_ASYNC);
			
		}
			if (collision(bouncer_x, bouncer_y, 42, 42, square2_x, square2_y, 32, 128, bouncer_dx, bouncer_dy) == 1) {
			bouncer_dx = -bouncer_dx;
			PlaySound(TEXT("PongBounce.wav"), NULL, SND_FILENAME | SND_ASYNC); 
		}
		}

		
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//here's the algorithm that turns key presses into events
		//a "key down" event is when a key is pushed
		//while a "key up" event is when a key is released

		//has something been pressed on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			//"keycode" holds all the different keys on the keyboard
			switch (ev.keyboard.keycode) {

				//if the up key has been pressed
			case ALLEGRO_KEY_UP:
				key2[0] = true;
				break;

			case ALLEGRO_KEY_W:
				key[0] = true;
				break;

				//if the down key has been pressed
			case ALLEGRO_KEY_DOWN:
				key2[1] = true;
				break;

			case ALLEGRO_KEY_S:
				key[1] = true;
				break;
			}
		}
		
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key2[0] = false;
				break;

			case ALLEGRO_KEY_W:
				key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key2[1] = false;
				break;

			case ALLEGRO_KEY_S:
				key[1] = false;
				break;

				//kill the program if someone presses escape
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		cout << "flag9" << endl;

		//RENDER SECTION
		//if the clock ticked but no other events happened, don't bother redrawing
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//paint black over the old screen, so the old square dissapears
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//the algorithm above just changes the x and y coordinates
			//here's where the bitmap is actually drawn somewhere else

			//BGpic = al_load_bitmap("BackGround.jpg");

			//al_draw_bitmap(BGpic, 0, 0, 0);

			al_draw_bitmap(square, square_x, square_y, 0);

			al_draw_bitmap(square2, square2_x, square2_y, 0);

			//al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			ball = al_load_bitmap("SmashBall.png");

			al_draw_bitmap(ball, bouncer_x, bouncer_y, 0);

			al_draw_bitmap(midwall, -50, 0, 0);

			al_draw_textf(font, al_map_rgb(255, 255, 255), 69, 40, ALLEGRO_ALIGN_LEFT, "%i", squarescore);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 570, 40, ALLEGRO_ALIGN_RIGHT, "%i", square2score);

			al_play_sample_instance(instance3);

			al_flip_display();
		}
	}
	cout << "flag10" << endl;

	al_destroy_bitmap(ball);
	al_destroy_bitmap(square);
	al_destroy_bitmap(square2);
	al_destroy_bitmap(bouncer);
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
	cout << "flag11" << endl;
} //main

int collision(int b1x, int b1y, int b1w, int b1h, int b2x, int b2y, int b2w, int b2h, int bouncer_dx, int bouncer_dy) {
	//if ball is to left of paddle
	if ((b1x + b1w < b2x) ||
		//if ball is above paddle
		(b1y + b1h < b2y) ||
		//if ball is below paddle
		(b1y > b2y + b2h) ||
		//if ball is to right of paddle
		(b1x > b2x + b2w)) {
		return 0;
		bouncer_dx = bouncer_dx * 3;
		bouncer_dy = bouncer_dy * 3;
	}
	else
		return 1;
}
