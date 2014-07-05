#ifndef __Game__
#define __Game__

#include "SDL2/SDL.h"

class Game{

    public:
        Game();
        ~Game();

        void render();
        void update();
        void handleEvents();
        void clean();

        bool loadMedia();
        bool running();
        SDL_Texture *loadTexture(std::string path);
        void handleKeyEvent(SDL_Keycode keyPressed);
        bool init(char const *title, int xpos, int ypos, int height, int width, int flags, bool fullScreen);

    private:

        bool success;
        bool m_bRunning;

        SDL_Renderer* g_pRenderer;

        //The window we'll be rendering to
        SDL_Window* gWindow;

        //The surface contained by the window
        SDL_Surface* gScreenSurface;
        SDL_Surface* tmpSurface;

        SDL_Texture* gTexture = NULL;

};

#endif /* defined(__Game__) */