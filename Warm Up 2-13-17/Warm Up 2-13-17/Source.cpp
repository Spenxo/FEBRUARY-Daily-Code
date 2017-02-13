#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

int main () {
	al_init();
	

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_FONT *font = al_load_ttf_font("TX_love.ttf", 72, 0);
	ALLEGRO_BITMAP *bitmap = NULL;


	display = al_create_display(1000, 1000);

	
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_rectangle(100, 100, 495, 700, al_map_rgb(150, 75, 175));
	al_draw_filled_rectangle(505, 100, 900, 700, al_map_rgb(150, 75, 175));
	
	al_draw_text(font, al_map_rgb(0, 0, 0), 1000/2, (1000/4), ALLEGRO_ALIGN_CENTRE, "Happy Vale ntines Day ");

	al_flip_display();

	al_rest(50.0);

	al_destroy_display(display);

	return 0;
}