#include "nest.hpp"
#include <iostream>
using namespace std;

Nest::Nest() {}

void Nest::wiggle() 
{
    if (p1 == 0){
        pf = 0;
    }
    else if (p1 == 1){
        pf = 140;
    }
    else if (p1 == 2){
        pf = 300;
        p1 = -1;
    }
    p1++;
    // see assets.png
    srcRect = {480, pf, 180, 150};
}
SDL_Rect Nest::getMover()
{
    return moverRect;
}

void Nest::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    wiggle();
    Controller::draw(gRenderer, assets);
}
Nest::Nest(int x, int y)
{
    // x, y location
    moverRect = {x, y, 50, 60};
}