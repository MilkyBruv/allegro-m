#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void init()
{

    al_init();
    al_init_image_addon();

}

void init_event()
{

    

}

void set_fps()
{



}

void init_devices(int devices[3])
{

    if (devices[0] == 1)
    {

        al_install_keyboard();

    }

    if (devices[1] == 1)
    {

        al_install_mouse();

    }

    if (devices[2] == 1)
    {

        al_install_joystick();

    }

}