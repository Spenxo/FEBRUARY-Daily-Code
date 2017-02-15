#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cmath>

const float FPS = 10000;
const int SCREEN_W = 640;
const int SCREEN_H = 480;

//change this number to change the size of the "marker tip" that draws the shape!
const int BOUNCER_SIZE = 3;

int main(int argc, char **argv) {

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_FONT *font = al_load_ttf_font("TX_love.ttf", 72, 0);
	ALLEGRO_SAMPLE *sample = al_load_sample("pretty.wav");
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 10.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;
	double t = 1;


	timer = al_create_timer(60.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//change the numbers to change the background color, 000 is black
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_load_sample("pretty.wav");

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{

		t++;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
				bouncer_dy = -bouncer_dy;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////
			//here's the parametric equations that determine the shape!!

			bouncer_x = 250 + 10 * (16 * (sin(t)*(sin(t))*(sin(t))));
			bouncer_y = 250 + (10 * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)))*-1;
			/////////////////////////////////////////////////////////////////////////////////////////////////////
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//a well-placed if statement here might make it blink

			//uncommenting this line makes it moving dots instead of picture
			//also, change the number values to change the background color 
			// al_clear_to_color(al_map_rgb(0,0,0)); 	

			al_set_target_bitmap(bouncer);
			//bouncer_x = 250 + 3.1 * (2.7 * cos(t) - tan(2 * t));
			//bouncer_y = 250 + 30 * (2 * sin(t) - sin(2 * t));

			//bouncer_x = 250 + 5 * (21 * cos(t) - 25 * cos(3.1*t));
			//bouncer_y = 300 + 10 * (2.1 * sin(6) - 25 * sin(3.1*t));

			//bouncer_x = 250 + 45 * (1.6*cos(t) - (.6*cos((1.6*t) / .6)));
			//bouncer_y = 250 + 45 * (1.6*sin(t) - (10.6*tan((1.6*t) / .6)));

			//bouncer_x = 250 + 45 * (1.6*cos(t) - (1.2*tan((1.6*t) / 6.6)));
			//bouncer_y = 250 + 45 * (1.6*sin(t) - (1.2*sin((16*t) / .6)));

	




			//mess with this last line here to change colors
			al_clear_to_color(al_map_rgb(255, 225, 255));
			al_set_target_bitmap(al_get_backbuffer(display));
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_text(font, al_map_rgb(200, 0, 0), 70, 60, 0, "Happy Valentines Day");
			al_play_sample(sample, 10.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_sample(sample);


	return 0;
}