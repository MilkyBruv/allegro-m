#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../lib/allegro_m.c"

int main(int argc, char const *argv[])
{

    const char* vshad = "./src/main/vert.glsl";
    const char* fshad = "./src/main/frag.glsl";

    float resolution[2] = {(float) 1280, (float) 720};

    //

    al_init();

    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);

    ALLEGRO_SHADER* shader = al_create_shader(ALLEGRO_SHADER_GLSL);
    al_attach_shader_source_file(shader, ALLEGRO_VERTEX_SHADER, vshad);
    al_attach_shader_source_file(shader, ALLEGRO_PIXEL_SHADER, fshad);

    if (!al_build_shader(shader))
    {

        printf("man this shader shit aint working fr");

    }

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    bool running = true;
    
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    //

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

    //

    al_init_image_addon();
    ALLEGRO_BITMAP* image = al_load_bitmap("./src/main/testimage.png");

    al_start_timer(timer);

    while (running)
    {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (alm_rectangles_collided(rect1, rect2))
        {

            al_set_window_title(display, "HITTIN");

        } else { al_set_window_title(display, "bruh"); }

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

            al_use_shader(shader);
            al_set_shader_sampler("b_tex0", al_get_backbuffer(display), 0);

            al_clear_to_color(al_map_rgb(255, 0, 0));

            al_draw_bitmap(image, rect1.x, rect1.y, 0);
            al_draw_bitmap(image, rect2.x, rect2.y, 0);

            al_flip_display();

        }

    }
        
    al_use_shader(NULL);
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);

    return 0;

}
