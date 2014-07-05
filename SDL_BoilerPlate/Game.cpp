#include <SDL2/SDL_video.h>
#include <SDL2_image/SDL_image.h>
#include <iosfwd>
#include <string>
#include "Game.h"



Game::Game(){

//    SDL_Texture* loadTexture( std::string path );

    SDL_Renderer* g_pRenderer = 0;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* tmpSurface = NULL;
}


 Game::~Game(){
     g_pRenderer = 0;
     gWindow = NULL;
     gScreenSurface = NULL;
     tmpSurface = NULL;
 }

SDL_Texture* Game::loadTexture( std::string path ){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }else{
        newTexture = SDL_CreateTextureFromSurface( g_pRenderer, loadedSurface );
        if( newTexture == NULL ){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

bool Game::loadMedia(){

    //Loading success flag
    bool success = true;
    //Load splash image
    gTexture = loadTexture( "/Users/jmausti3/Developer/c_cpp/SDL_BoilerPlate/Media/hello_world.bmp" );
    if( gTexture == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", "", SDL_GetError() );
        success = false;
    }
    return success;
}

bool Game::init(char const *title, int xpos, int ypos, int height, int width, int flags, bool fullScreen) {

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) >= 0){

        gWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if(gWindow != 0 ){
            g_pRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        }
        if(gWindow !=0){
            printf("init successful\n");
            if(g_pRenderer != 0 ){
                printf("renderer creation successful\n");
                SDL_SetRenderDrawColor(g_pRenderer, 155, 155, 155, 255);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
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

    m_bRunning = true;

    return true;
}

void Game::render(){
    SDL_RenderClear(g_pRenderer); // clear renderer to the draw color
    //Render texture to screen
    SDL_RenderCopy( g_pRenderer, gTexture, NULL, NULL );
    SDL_RenderPresent(g_pRenderer); // draw to the screen


}

void Game::clean(){
    printf("cleaning game");
    if(gTexture != NULL)
        SDL_DestroyTexture( gTexture );
    if(tmpSurface != NULL)
        SDL_FreeSurface( tmpSurface );
    if(gScreenSurface != NULL)
        SDL_FreeSurface( gScreenSurface );

    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(g_pRenderer);

    gWindow = NULL;
    g_pRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

void Game::handleEvents(){
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                m_bRunning = false;
                break;
            case SDL_KEYDOWN:
                handleKeyEvent(event.key.keysym.sym);
                break;
            default:
                break;
        }
    }
}

void Game::handleKeyEvent(SDL_Keycode keyPressed) {

    switch (keyPressed) {

        case SDLK_RIGHT:
            printf("right pressed\n");
            break;
        case SDLK_LEFT:
            printf("left pressed\n");
            break;
        case SDLK_DOWN:
            printf("down pressed\n");
            break;
        case SDLK_UP:
            printf("up pressed\n");
            break;
        case SDLK_SPACE:
            printf("space pressed\n");

            if(!loadMedia()){
                printf("unable to load surface\n");
                m_bRunning = false;
                break;
            } else {
                loadMedia();
                break;
            }

        case SDLK_ESCAPE:
            printf("escape pressed\n");
            m_bRunning = false;
            break;

        default:
            break;
    }
}

bool Game::running() {
    if(!m_bRunning)
        return false;
    else
        return true;
}

void Game::update() {
//
//    SDL_BlitSurface(tmpSurface, NULL, gScreenSurface, NULL);
//    SDL_UpdateWindowSurface( gWindow );
}


