#include "common.h"
#include "shadertoy.h"
#include "filesystem.h"
#include "shaderprogram.h"

int main(int argc, char *argv[])
{
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initilizated SDL Failed: %s", SDL_GetError());
        return -1;
    }

    //std::vector<std::string> texFiles;

    if (argc <= 1)
    {
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "No specified fragment shader source file\n");
        return EXIT_FAILURE;
    }

	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s\n", argv[1]);
    char *source = FileSystem::readAll(argv[1]);

	if (source == nullptr)
	{
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Read fragment shader file failed\n");
		return EXIT_FAILURE;
	}

    ShaderToy shaderToy;
    shaderToy.addUserFragmentMainCode(source);
    shaderToy.run();

    delete[] source;

    SDL_Quit();
    return 0;
}
