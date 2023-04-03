#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../lib/allegro_m.c"

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(int argc, char const *argv[])
{

    int iw = 500, 
        ih = 500, 
        ix = 0, 
        iy = 0, 
        diw = 100, 
        dih = 100, 
        dw = 0, 
        dh = 0;
    bool running = true;
    float scale;

    al_init();

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_set_window_title(display, "Bitmap scale test");

    ALM_RECTANGLE rect1;
    ALM_RECTANGLE rect2;

    rect1.x = 0;
    rect1.y = 0;
    rect1.width = 32;
    rect1.height = 32;

    rect2.x = 0;
    rect2.y = 0;
    rect2.width = 32;
    rect2.height = 32;

    al_init_image_addon();
    ALLEGRO_BITMAP* image = al_load_bitmap("./src/main/testimage.png");
    ALLEGRO_BITMAP* inner_display = al_create_bitmap(100, 100);

    al_set_target_bitmap(inner_display);
    al_clear_to_color(al_map_rgb(0, 255, 0));
    al_draw_bitmap(image, 0, 0, 0);
    al_set_target_bitmap(al_get_backbuffer(display));

    al_start_timer(timer);

    while (running)
    {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (alm_rectangles_collided(rect1, rect2))
        {
            
            //

        }

        if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
        {

            al_acknowledge_resize(display);

            dw = al_get_display_width(display);
            dh = al_get_display_height(display);

            if (dw > dh)
            {
                
                iw = iw;
                ih = dh;

            } else if (dw < dh)
            {
                
                iw = dw;
                ih = ih;

            } else if (dw == dh)
            {
                
                iw = iw;
                ih = ih;

            }

            iw = iw * scale;
            ih = ih * scale;

            ix = (al_get_display_width(display) / 2) - (iw / 2);
            iy = (al_get_display_height(display) / 2) - (ih / 2);

        }

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            running = false;

        }

        if (event.type == ALLEGRO_EVENT_KEY_UP)
        {

            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {

                rect1.x -= 16;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {

                rect1.x += 16;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_UP)
            {

                rect1.y -= 16;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {

                rect1.y += 16;

            }

        }

        if (event.type == ALLEGRO_EVENT_TIMER)
        {

            al_clear_to_color(al_map_rgb(255, 0, 0));

            if (iw >= 5 && ih >= 5)
            {

                al_draw_scaled_bitmap(inner_display, 0, 0, 100, 100, ix, iy, iw, ih, 0);

            } else
            {

                al_draw_scaled_bitmap(inner_display, 0, 0, 100, 100, ix, iy, 5, 5, 0);

            }

            al_flip_display();

        }

    }
        
    al_use_shader(NULL);
    al_destroy_display(display);
    // al_destroy_display(inner_display);
    // al_destroy_display(image);
    al_uninstall_keyboard();
    al_destroy_timer(timer);

    return 0;

}
