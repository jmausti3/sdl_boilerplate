//  main.cpp
//  SDL_BoilerPlate
//
//  Created by Jon Austin on 6/28/14.
//  Copyright (c) 2014 adfad. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

Game* game = 0;


int main(int argc, const char * argv[])
{

    const char * windowTitle = "Chapter 1: creating a window";
    int height = 640;
    int width = 480;
    game = new Game();

    game->init(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN, false);

    while (game->running()){
        game->handleEvents();
        game->update();
        game->render();

    }

    game->clean();

    return 0;
}
