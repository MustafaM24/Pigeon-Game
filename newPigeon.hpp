#include <SDL.h>
#include <iostream>
#include "Controller.hpp"
#pragma once
#include "egg.hpp"
using namespace std;

class newPigeon : 
    public Controller
        {
            int p2 = 0;
            int p2f;
            public:
                void grow();
                void draw(SDL_Renderer *, SDL_Texture *assets);
                newPigeon(int, int);    
                SDL_Rect getMover(); 
        };