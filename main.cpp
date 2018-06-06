#include "common.h"
#include "shadertoy.h"
#include "filesystem.h"
#include "shaderprogram.h"

int main(int argc, char *argv[])
{
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initilizated SDL Failed: %s", SDL_GetError());
        return -1;
    }

    //std::vector<std::string> texFiles;

    if (argc < 1)
        return EXIT_FAILURE;

    char *source = FileSystem::readAll(argv[1]);

    ShaderToy shaderToy;
    shaderToy.addUserFragmentMainCode(source);
    shaderToy.run();

    delete[] source;

    SDL_Quit();
    return 0;
}
