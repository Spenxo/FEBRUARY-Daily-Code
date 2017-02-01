#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
using namespace std;

int main()
{
	ALLEGRO_DISPLAY *display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_primitives_addon();

	display = al_create_display(640, 480);
	

	al_clear_to_color(al_map_rgb(4, 4, 30));

	al_draw_filled_triangle(100, 100, 200, 200, 40, 479, al_map_rgb_f (0.5, 0.7, 0.3));
	al_draw_filled_triangle(300, 300, 400, 400, 500, 60, al_map_rgb_f(0.6, 0.3, 0.8));
	al_draw_filled_triangle(200, 200, 300, 250, 250, 300, al_map_rgb_f(0.4, 0.2, 1.6));

	al_flip_display();

	al_rest(30.0);

	al_destroy_display(display);
}