//  main.cpp
//  SDL_BoilerPlate
//
//  Created by Jon Austin on 6/28/14.
//  Copyright (c) 2014 adfad. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"





//
//
//bool loadMedia(){
//
//    //Loading success flag
//    bool success = true;
//    //Load splash image
//    gHelloWorld = SDL_LoadBMP( "/Users/jmausti3/Developer/c_cpp/SDL_BoilerPlate/Media/hello_world.bmp" );
//    if( gHelloWorld == NULL ) { printf( "Unable to load image %s! SDL Error: %s\n", "", SDL_GetError() );
//        success = false;
//    }
//    return success;
//}
//
//void close(){
//
//    //Deallocate surface
//    SDL_FreeSurface( gHelloWorld ); gHelloWorld = NULL;
//    //Destroy window
//    SDL_DestroyWindow( gWindow );
//    gWindow = NULL;
//    //Quit SDL subsystems
//    SDL_Quit();
//}
//
//void render(){
//    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
//    SDL_RenderClear(g_pRenderer);
//    SDL_RenderPresent(g_pRenderer);
//}

Game* game = 0;


int main(int argc, const char * argv[])
{

    const char * windowTitle = "Chapter 1: creating a window";
    int height = 640;
    int width = 480;
    game = new Game();

    game->init(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);

    while (game->running()){
        game->handleEvents();
        game->update();
        game->render();

    }

    game->clean();

    return 0;
}
