#include <SDL.h>
#include <iostream>
#include "Controller.hpp"
#pragma once
using namespace std;

class Nest : public Controller
{

    // THESE TWO INTEGARS ARE FOR CHANGING THE IMAGE OF NEST (WIGGLE)
    int p1 = 0;
    int pf;

public:
    void wiggle();
    void draw(SDL_Renderer *, SDL_Texture *assets);
    Nest(int, int); // my main construtor
    Nest(); // default constructor

    SDL_Rect getMover(); // for coordinates & collison
};
