#include "Controller.hpp"
#include <iostream>
using namespace std;

void Controller::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

Controller::~Controller()
{
}