#include<iostream>
#include "HUMania.hpp"
#include <list>

using namespace std;

void HUMania::drawObjects()
{
    HUMania::checkpig();

    for (list<newPigeon *>::iterator l = babyP.begin(); l != babyP.end(); l++)
    {
        // int counter = 0; (extra function)
        (*l)->draw(gRenderer, assets); 

        if ((*l)->getMover().x > 952)
        {
            // *l = *l - 800;
            // counter = counter + 1;  //(to make pigeon come back from other side)
            delete (*l);
            l = babyP.erase(l);
        }
        // if (counter == 5)
        // {
        //     delete (*l);  //(to qill pigeon after 5 rounds)
        //     l = babyP.erase(l);
        // }
    }

    for (list<Pigeon *>::iterator m = pigeons.begin(); m != pigeons.end(); m++)
    {
        (*m)->draw(gRenderer, assets); 

        //  IF PIEGON REAHCES AT EXTREME RIGHT SO DESTROY IT
        if ((*m)->getMover().x > 1000) //(1000 is so that the pigeon doesnt dissapear mid way passing through the edge)
        {                              // it will now get deleted after leaving screen completely
            delete (*m);
            m = pigeons.erase(m);
        }
    }
    for (list<Egg *>::iterator n = eggs.begin(); n != eggs.end(); n++)
    {
        (*n)->draw(gRenderer, assets);
    }
    for (list<Nest *>::iterator q = nests.begin(); q != nests.end(); q++)
    {
        (*q)->draw(gRenderer, assets);
    }
}

// DESTROY AND DEALLOCATE ALL DYNAMICAL/LINKED LISTS
void HUMania::destroyeverything()
{
    for (list<Pigeon *>::iterator m = pigeons.begin(); m != pigeons.end(); m++)
    {
        // DESTROYING EVERY OBJECT IN THE LIST
        delete *m;
        m = pigeons.erase(m);
    }

    for (list<Egg *>::iterator n = eggs.begin(); n != eggs.end(); n++)
    {
        // DESTROYING EVERY OBJECT IN THE LIST
        delete (*n);
        n = eggs.erase(n);
    }

    for (list<Nest *>::iterator q = nests.begin(); q != nests.end(); q++)
    {
        // DESTROYING EVERY OBJECT IN THE LIST
        delete (*q);
        q = nests.erase(q);
    }

    for (list<newPigeon *>::iterator l = babyP.begin(); l != babyP.end(); l++)
    {
        // DESTROYING EVERY OBJECT IN THE LIST
        delete (*l);
        l = babyP.erase(l);
    }

    // DEALLOCATING MEMORY AND DELETING ALL LINKED LISTS
    pigeons.clear();
    nests.clear();
    eggs.clear();
    babyP.clear();
}

// FOR CHECKING THE COLLLISION BETWEEN EGG &NEST
void HUMania::checkpig()
{
    if (!nests.empty()) // IF NEST LIST IS NOT EMPTY
    {
        for (list<Nest *>::iterator m = nests.begin(); m != nests.end(); m++)
        {                                                                      // m = object 1
            for (list<Egg *>::iterator n = eggs.begin(); n != eggs.end(); n++) // n = object 2
            {
                SDL_Rect rect1 = (*m)->getMover();       // OBJECT 1 COORDINATES
                SDL_Rect rect2 = (*n)->getMover();       // OBJECT 2 COORDINATES
                if (SDL_HasIntersection(&rect1, &rect2)) // USING SDL FUNCTION FOR COLLISON COMPARSON
                {
                    babyP.push_back(new newPigeon((*m)->getMover().x, (*m)->getMover().y)); // DRAWING newPigeon PIGEON

                    delete (*n); // DELET THE HETCHED EGG
                    // IF WE DO NOT DELETE THE HETCHED EGG HERE SO IT WILL MAKE INFINITE pigeons
                    n = eggs.erase(n); // DEALOCATE IT FROM MEMORY/LIST
                }
            }
        }
    }
}

void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked: " << x << " -- " << y << std::endl;

    int n = rand() % 60 + 1; // FOR random generation of pigeon
    cout << "random num generated = " << n << endl;
    if (n <= 20)
    {
        pigeons.push_back(new Pigeon(x, y)); // creates pigeon at clicked x and y (ON THE BASIS OF RANDOM NUMBER GENERATED)
    }
    else if (y < 300) //n > 20 && n <= 40 && to restrict probability
    {
        eggs.push_back(new Egg(x, y)); // creates egg above y axis 300
    }
    else if (y > 300)
    {
        nests.push_back(new Nest(x, y)); // creates nest below y axis at 300
    }
}

HUMania::HUMania(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst) {}
