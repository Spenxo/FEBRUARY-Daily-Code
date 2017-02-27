#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

int main() {

	ALLEGRO_DISPLAY *display = NULL;

	al_init();

	al_init_primitives_addon();

	display = al_create_display(640, 480);
	float Picture[5][5] = { {200,30},{200,200},{400,90},{300,200},{200,400} };

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_ribbon(*Picture, sizeof(*Picture), al_map_rgb(220, 10, 150), 100, 5);

	al_flip_display();

	al_rest(30.0);

	al_destroy_display(display);

	return 0;

}
