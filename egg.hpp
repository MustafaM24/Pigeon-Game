#include <SDL.h>
#include <iostream>
#include "Controller.hpp"
#pragma once
using namespace std;

class Egg : 
    public Controller
    {
        public:
            void drop();
            void draw(SDL_Renderer *, SDL_Texture *assets);
            Egg(int, int);
            SDL_Rect getMover(); 
    };
