#include "window.h"

Window::Window()
    : mWindow(nullptr)
{
    createWindow();
}

Window::~Window()
{
    closeWindow();
}

int Window::posX() const
{
    if (mWindow)
    {
        int x = 0, y = 0;
        SDL_GetWindowPosition(mWindow, &x, &y);
        return x;
    }

    return SDL_WINDOWPOS_CENTERED;
}

int Window::posY() const
{
    if (mWindow)
    {
        int x = 0, y = 0;
        SDL_GetWindowPosition(mWindow, &x, &y);
        return y;
    }

    return SDL_WINDOWPOS_CENTERED;
}

int Window::width()
{
    if (mWindow)
    {
        SDL_GetWindowSize(mWindow, &(mMode.w), &(mMode.h));
        return mMode.w;
    }

    return WINDOW_DEFAULT_WIDTH;
}

int Window::height()
{
    if (mWindow)
    {
        SDL_GetWindowSize(mWindow, &(mMode.w), &(mMode.h));
        return mMode.w;
    }

    return WINDOW_DEFAULT_HEIGHT;
}

void Window::run()
{
    if (!mWindow && !mContext)
        return;

    bool done = true;
    SDL_Event event;

    initilizeGL();

    while (done)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                keydownEvent(&(event.key));
                break;

            case SDL_KEYUP:
                keyupEvent(&(event.key));
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseButtonEvent(&(event.button));
                break;

            case SDL_MOUSEMOTION:
                mouseMotionEvent(&(event.motion));
                break;

            case SDL_WINDOWEVENT:
                break;

            case SDL_QUIT:
                done = false;
                break;

            default:
                break;
            }
        }

        renderGL();
    }

    return;
}

void Window::move(int x, int y)
{
    if (mWindow)
    {
        SDL_SetWindowPosition(mWindow, x, y);
    }
}

void Window::resize(int w, int h)
{
    if (mWindow)
    {
        SDL_SetWindowSize(mWindow, w, h);
    }
}

void Window::setTitile(const std::string &title)
{
    if (mWindow)
    {
        SDL_SetWindowTitle(mWindow, title.c_str());
    }
}

void Window::initilizeGL()
{
}

void Window::resizeGL(int w, int h)
{
}

void Window::renderGL()
{
    SDL_GL_SwapWindow(mWindow);
}

void Window::mouseButtonEvent(SDL_MouseButtonEvent *event)
{

}

void Window::mouseMotionEvent(SDL_MouseMotionEvent *event)
{
}

void Window::keydownEvent(SDL_KeyboardEvent *event)
{
}

void Window::keyupEvent(SDL_KeyboardEvent *event)
{
}

void Window::createWindow()
{
    mMode.w = WINDOW_DEFAULT_WIDTH;
    mMode.h = WINDOW_DEFAULT_HEIGHT;

    if (SDL_WasInit(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initilize SDL: %s",
                     SDL_GetError());
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    mWindow = SDL_CreateWindow("ShaderToy",
              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              mMode.w, mMode.h,
              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if (!mWindow)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s",
                     SDL_GetError());
        return;
    }

    SDL_GetWindowDisplayMode(mWindow, &mMode);

    mContext = SDL_GL_CreateContext(mWindow);
    if (!mContext)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create OpenGL Context: %s",
                     SDL_GetError());
        SDL_DestroyWindow(mWindow);
        return;
    }

    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);

    SDL_GL_SetSwapInterval(1);
}

void Window::closeWindow()
{
    if (mContext)
        SDL_GL_DeleteContext(mContext);

    if (mWindow)
        SDL_DestroyWindow(mWindow);

    mContext = nullptr;
    mWindow = nullptr;
}
