
#include "pigeon.hpp"
#include <iostream>
using namespace std;

void Pigeon::fly() // animate pigeon
{
    if (count == 0){
        p3f = 0;
    }
    else if (count == 1){
        p3f = 150;
    }
    else if (count == 2){
        p3f = 300;
        count = -1;
    }
    count++;           
    srcRect = {0, p3f, 160, 133}; 
    moverRect.x += 5; 
    if (moverRect.y > 10)
    { 
        moverRect.y -= 2;
    }
}
void Pigeon::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    fly();
    Controller::draw(gRenderer, assets);
}
Pigeon::Pigeon(int x, int y)
{
    // x, y coordinates 
    moverRect = {x, y, 50, 60};
}
SDL_Rect Pigeon::getMover()
{
    //  collision coordinates of egg and nest
    return moverRect;
}