// #include<SDL.h>
// #include "pigeon.hpp"
// class HUMania{
//     SDL_Renderer *gRenderer;
//     SDL_Texture *assets;

//     //Right now we're creating one pigeon, 
//     // In the solution you have to create vectors of pigeons, eggs, and nests    
//     Pigeon p1;

//     public:
//     HUMania(SDL_Renderer *, SDL_Texture *);
//     void drawObjects(); 
//     void createObject(int, int);
    
// };

#include <SDL.h>
#include "pigeon.hpp"
#include "egg.hpp"
#include "nest.hpp"
#include "newPigeon.hpp"
#include "Controller.hpp"
#include <iostream>
#include <vector>
#include <list>
#pragma once
using namespace std;

class HUMania
{

    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    // list of all objects
    list<Pigeon *> pigeons;
    list<Egg *> eggs;
    list<Nest *> nests;
    list<newPigeon *> babyP;

public:
    HUMania(SDL_Renderer *, SDL_Texture *);
    void drawObjects();
    void createObject(int, int);
    void checkpig();
    void destroyeverything(); // delete memory
};