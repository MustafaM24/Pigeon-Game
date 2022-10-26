#include "newPigeon.hpp"
#include <iostream>
using namespace std;

void newPigeon::grow()
{
    if (p2 == 0){
        p2f = 0;
    }
    else if (p2 == 1){
        p2f = 150;
    }
    else if (p2 == 2){
        p2f = 300;
        p2 = -1;
    }
    p2++;                        
    srcRect = {0, p2f, 160, 133};
    moverRect.x += 5; // x coordinate
    if (moverRect.y > 10)
    {
        // y coordinate
        moverRect.y -= 2;
    }
    if (moverRect.w < 49)
    {
        // size increase
        moverRect.w += 3;
    }
    if (moverRect.h < 59)
    {
        // size increase
        moverRect.h += 3;
    }
}

void newPigeon::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    grow();
    Controller::draw(gRenderer, assets);
}
newPigeon::newPigeon(int x, int y)
{
    moverRect = {x, y, 5, 6};
}
SDL_Rect newPigeon::getMover()
{
    return moverRect;
}