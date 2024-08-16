#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

class Display {
public:
    Display();
    ~Display();

    void Clear();
    void SetPixel(int x, int y, SDL_Color color);
    void Update();
    bool ProcessInput();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    static const int WIDTH = 64;
    static const int HEIGHT = 64;
    static const int SCALE = 10; // Scale up the window size for visibility
};

#endif // DISPLAY_H
