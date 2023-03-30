#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>



typedef struct ALM_RECTANGLE
{

    int x;
    int y;
    int width;
    int height;

} ALM_RECTANGLE;



bool alm_rectangles_collided(ALM_RECTANGLE rect1, ALM_RECTANGLE rect2)
{

    if (rect1.x < rect2.x + rect2.width - 1 && rect1.x + rect1.width - 1 > rect2.x &&
        rect1.y < rect2.y + rect2.height - 1 && rect1.y + rect1.height - 1 > rect2.y)
    {

        return true;

    }

    return false;

}



ALLEGRO_BITMAP* alm_create_inner_display(const signed int width, const signed int height)
{

    ALLEGRO_BITMAP* bitmap_display = al_create_bitmap(width, height);
    al_set_target_bitmap(bitmap_display);

    return bitmap_display;

}



ALLEGRO_BITMAP* alm_get_sub_bitmap(ALLEGRO_BITMAP* bitmap, const int x, const int y, const signed int width, const signed int height, ALLEGRO_BITMAP* display)
{

    ALLEGRO_BITMAP* target_bitmap = al_create_bitmap(width, height);
    al_set_target_bitmap(target_bitmap);
    al_draw_bitmap_region(bitmap, x, y, width, height, 0, 0, 0);
    al_set_target_bitmap(display);

    return target_bitmap;

}