#include <stdio.h>
#include <string.h>
#include "Slider.h"

#define max(a, b) ((a) > (b)? (a) : (b))
#define min(a, b) ((a) < (b)? (a) : (b))
#define font_size 15

const int widthOftarget = 15;
const int heightOftarget = 30;

Slider::Slider(int pos_x = 0, int pos_y = 0)
{
    track_x = pos_x;
    track_y = pos_y;

    target_x = track_x + lengthOftrack;
    target_y = track_y;
    target_color = al_map_rgb(90, 70, 0);

    degree = 1.0;

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf", font_size, 0); // load font
    strncpy(label, "label", 20);
}

Slider::~Slider()
{
    al_destroy_font(font);
}

void
Slider::Draw()
{
    int draw_x = target_x - widthOftarget/2;
    int draw_y = target_y - heightOftarget/2;

    al_draw_line(track_x, track_y, track_x + lengthOftrack, track_y, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rectangle(draw_x, draw_y, draw_x + widthOftarget, draw_y + heightOftarget, target_color);
    al_draw_text(font, al_map_rgb(255, 255, 255), 50 , track_y - 35, ALLEGRO_ALIGN_LEFT, label);
}

void
Slider::set_color(ALLEGRO_COLOR color)
{
    target_color = color;
}

void
Slider::set_label_content(const char *content)
{
    strncpy(label, content, 20);
}

float
Slider::Drag(int update_x, int update_y)
{
    if(update_x < target_x)
        target_x = max(update_x, track_x);
    else
        target_x = min(update_x, track_x + lengthOftrack);

    degree = ((float)(target_x - track_x) / (float)lengthOftrack);

    return degree;
}

bool
Slider::isClicked(int mouse_x, int mouse_y)
{
    int real_x = target_x - widthOftarget/2;
    int real_y = target_y - heightOftarget/2;

    if(mouse_x >= real_x && mouse_x <= real_x + widthOftarget)
    {
        if(mouse_y >= real_y && mouse_y <= real_y + heightOftarget)
        {
            return true;
        }
    }
    return false;
}
