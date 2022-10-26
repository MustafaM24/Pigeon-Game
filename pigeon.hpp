// #include<SDL.h>

// class Pigeon{
// SDL_Rect srcRect, moverRect;

// public:
//     // add the fly function here as well.
//     void draw(SDL_Renderer*, SDL_Texture* assets);
//     Pigeon(); // may add other overloaded constructors here... 
// };

#include <SDL.h>
#include <iostream>
#include "Controller.hpp"
#pragma once
using namespace std;

class Pigeon : 
    public Controller
        {
            int count = 0;
            int p3f;

            public:
                void fly();
                void draw(SDL_Renderer *, SDL_Texture *assets);

                Pigeon(int, int);

                SDL_Rect getMover();
        };
