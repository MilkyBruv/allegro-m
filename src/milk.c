#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

const signed int INIT_KEYBOARD = 1;
const signed int INIT_MOUSE = 1;
const signed int INIT_JOYSTICK = 1;

const signed int SCALE_INNER_DISPLAY = 1;
const signed int FIT_INNER_DISPLAY = 2;

typedef struct EVENT_QUEUE
{

    ALLEGRO_EVENT_QUEUE* al_event_queue;

} EVENT_QUEUE;

typedef struct DISPLAY
{

    ALLEGRO_DISPLAY* al_display;

} DISPLAY;

typedef struct EVENT_SOURCE
{

    ALLEGRO_EVENT_SOURCE* al_event_source;

} EVENT_SOURCE;

typedef struct TIMER
{

    ALLEGRO_TIMER* al_timer;

} TIMER;

typedef struct IMAGE
{

    ALLEGRO_BITMAP* bitmap;

} IMAGE;

void init()
{

    al_init();
    al_init_image_addon();

}

EVENT_QUEUE* init_event_queue()
{

    EVENT_QUEUE* event_queue;
    event_queue->al_event_queue = al_create_event_queue();

    return event_queue;

}

void add_event(EVENT_QUEUE* event_queue_, EVENT_SOURCE* event_source_)
{

    al_add_event_source(event_queue_->al_event_queue, event_source_->al_event_source);

}

DISPLAY* create_display(int width_, int height_, int mode)
{

    DISPLAY* display;
    display->al_display = al_create_display(width_, height_);

    return display;

}

TIMER* create_fps_timer(const signed int fps_)
{

    TIMER* timer;
    timer->al_timer = al_create_timer(1.0 / fps_);

}

void init_devices(int devices[3])
{

    if (devices[0] != NULL)
    {

        al_install_keyboard();

    }

    if (devices[1] != NULL)
    {

        al_install_mouse();

    }

    if (devices[2] != NULL)
    {

        al_install_joystick();

    }

}