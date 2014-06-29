#include <SDL2/SDL_video.h>
#include "Game.h"


SDL_Renderer* g_pRenderer = 0;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

bool Game::loadMedia(){

    //Loading success flag
    bool success = true;
    //Load splash image
    gScreenSurface = SDL_LoadBMP( "/Users/jmausti3/Developer/c_cpp/SDL_BoilerPlate/Media/hello_world.bmp" );
    if( gScreenSurface == NULL ) { printf( "Unable to load image %s! SDL Error: %s\n", "", SDL_GetError() );
        success = false;
    }
    return success;
}


bool Game::init(char const *title, int xpos, int ypos, int height, int width, int flags, bool fullScreen) {

    m_bRunning = true;

    SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) >= 0){

        gWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if(gWindow != 0 ){
//            g_pRenderer = SDL_CreateRenderer(gWindow, -1, 0);
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
        if(gWindow !=0){
            printf("init successful");
            g_pRenderer  = SDL_CreateRenderer(gWindow, -1, 0);
            if(g_pRenderer != 0 ){
                printf("rednerer creation successful\n");
                SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
            }else {
                printf("render init fail\n");
                return false;
            }
        }else {
            printf("window init fail");
        }
    }else {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false; // sdl could not initialize
    }

    return true;
}

void Game::render(){
    SDL_RenderClear(g_pRenderer); // clear renerer to dthe draw color

    SDL_RenderPresent(g_pRenderer); // draw to the screen
}

void Game::clean(){
    printf("cleaning game");
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(g_pRenderer);
    SDL_Quit();
}

void Game::handleEvents(){
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}
