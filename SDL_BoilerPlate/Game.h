#ifndef __Game__
#define __Game__

#include "SDL2/SDL.h"
class Game{

public:
    Game() {}
    ~Game() {}


    void render(){}
    void update(){}
    void handleEvents(){}
    void clean(){}

    bool loadMedia(){return success;}
    bool running(){ return m_bRunning;}

    bool init(char const *title, int xpos, int ypos, int height, int width, int flags, bool fullScreen);

private:

    bool success;
    bool m_bRunning;

};

#endif /* defined(__Game__) */