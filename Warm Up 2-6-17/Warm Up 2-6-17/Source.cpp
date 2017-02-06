#include <iostream>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
using namespace std;

int main()
{
	ALLEGRO_DISPLAY *display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(800, 800);
	al_init_font_addon();
	al_init_primitives_addon();
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(125, 125, 675, 675, al_map_rgb_f(0, 0, 0));
	al_draw_filled_rectangle(150, 150, 650, 650, al_map_rgb_f(255, 255, 255));
	al_draw_text(font, al_map_rgb(0, 0, 0), 400, 300, ALLEGRO_ALIGN_CENTER, "Speed Limit 100");
	al_flip_display();
	al_rest(30.0);
	al_destroy_display(display);
	return 0;
}