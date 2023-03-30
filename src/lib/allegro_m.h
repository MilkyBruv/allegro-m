#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct ALM_RECTANGLE
{

    int x;
    int y;
    int width;
    int height;

} ALM_RECTANGLE;

bool alm_rectangles_collided(ALM_RECTANGLE rect1, ALM_RECTANGLE rect2);

ALLEGRO_BITMAP* alm_create_inner_display(const signed int width, const signed int height);

ALLEGRO_BITMAP* alm_get_sub_bitmap(ALLEGRO_BITMAP* bitmap, const int x, const int y, const signed int width, const signed int height, ALLEGRO_BITMAP* display);
