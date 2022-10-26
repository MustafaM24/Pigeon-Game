#include "egg.hpp"
#include <iostream>
#include "newPigeon.hpp"
using namespace std;


void Egg::drop() 
{
    if (moverRect.y < 534)
    {
        moverRect.y += 4;
        srcRect = {200, 0, 160, 200};
    }
    else
    {
        srcRect = {170, 200, 300, 250};
        if (moverRect.w == 35 && moverRect.h == 45)
        {
            moverRect.w += 15;
            moverRect.h += 15;
        }
    }
}

void Egg::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop();
    Controller::draw(gRenderer, assets);
}

Egg::Egg(int x, int y)
{
    // (x,y) is coordinate of click
    moverRect = {x, y, 35, 45};
}

SDL_Rect Egg::getMover()
{ 
    return moverRect;
}