#ifndef QRTOWER_H_INCLUDED
#define QRTOWER_H_INCLUDED

#include "Tower.h"

class QRTower : public Tower
{
public:
    QRTower(int mouse_x = 0, int mouse_y = 0) : Tower(mouse_x, mouse_y)
    {
        type = QRTOWER;

        circle->r = 100;
        attack_frequency = 60;
        attack_velocity = 5;
        attack_harm_point = 10;
        img = al_load_bitmap("./Tower/QRTower.png");
        attack_img = al_load_bitmap("./Tower/QRTower_Beam.png");
    }

    int getWidth() override { return TowerWidth[QRTOWER]; }
    int getHeight() override { return TowerHeight[QRTOWER]; }
};

#endif // QRTOWER_H_INCLUDED
