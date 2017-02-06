#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

int main(){
	cout << "target logo" << endl;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *image = NULL;
	

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	ALLEGRO_FONT* font = al_create_builtin_font();
	display = al_create_display(800, 800);
	


	al_clear_to_color(al_map_rgb(255, 255, 255));

	
	al_draw_circle(400, 400, 300, al_map_rgb_f(265, -10, -10), 100);
	al_draw_filled_circle(400, 400, 175, al_map_rgb_f(265, -10, -10));
	al_draw_text(font, al_map_rgb(0, 0, 0), 680, 680, ALLEGRO_ALIGN_CENTER, "R");
	image = al_load_bitmap("R.png");
	al_flip_display();

	al_rest(30.0);

	al_destroy_display(display);
}