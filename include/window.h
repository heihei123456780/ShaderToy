#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "common.h"

#ifndef WINDOW_DEFAULT_WIDTH
    #define WINDOW_DEFAULT_WIDTH 640
#endif

#ifndef WINDOW_DEFAULT_HEIGHT
    #define WINDOW_DEFAULT_HEIGHT 480
#endif

class Rectangle;

class Window
{
public:
    Window();
    ~Window();

    int posX() const;
    int posY() const;

    int width();
    int height();

    const Rectangle *rect() const { return mRect; }
    const Rectangle *drawableRect() const { return mDrawRect; }

    void run();

    void move(int x, int y);
    void resize(int w, int h);
    void setTitile(const std::string &title);

protected:
    virtual void initilizeGL();
    virtual void resizeGL(int w, int h);
    virtual void renderGL();

    virtual void mouseButtonEvent(SDL_MouseButtonEvent *event);
    virtual void mouseMotionEvent(SDL_MouseMotionEvent *event);
    virtual void keydownEvent(SDL_KeyboardEvent *event);
    virtual void keyupEvent(SDL_KeyboardEvent *event);

private:
    void createWindow();
    void closeWindow();

    SDL_Window *mWindow;
    SDL_DisplayMode mMode;
    SDL_GLContext mContext;
    Rectangle *mRect, *mDrawRect;
};

#endif // GLWINDOW_H
