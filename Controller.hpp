#include <SDL.h>
#include <iostream>
#pragma once
using namespace std;

class Controller
{
    protected:
        SDL_Rect srcRect, moverRect;

    public:
        void draw(SDL_Renderer *, SDL_Texture *assets);

        ~Controller();
};
