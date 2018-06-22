#include "common.h"
#include "shadertoy.h"
#include "filesystem.h"
#include "shaderprogram.h"

void printUsage();

int main(int argc, char *argv[])
{
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initilizated SDL Failed: %s", SDL_GetError());
        return -1;
    }

    bool hasShader = false;
    bool hasTexture = false;

    std::vector<const char *> texFiles;
    char *shaderSource = nullptr;

    if (argc <= 1)
    {
        printUsage();
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-shader") == 0 && i + 1 < argc)
        {
            shaderSource = FileSystem::readAll(argv[i + 1]);
            hasShader = true;
            i++;
        }

        if (strcmp(argv[i], "-channels") == 0)
        {
            int j = 0;
            for (j = i + 1; j < argc; j++)
            {
                const char *ext = FileSystem::fileExtName(argv[j]);
                if (strcmp(ext, "png") == 0 || strcmp(ext, "bmp") == 0)
                {
                    hasTexture = true;
                    texFiles.push_back(argv[j]);
                }
                if (texFiles.size() >= 4)
                    break;
            }

            i += j;
        }
    }


    if (hasShader == false)
    {
        printUsage();
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "No specified fragment shader source file\n");
        return EXIT_FAILURE;
    }

    if (shaderSource == nullptr)
	{
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Read fragment shader file failed\n");
		return EXIT_FAILURE;
	}

    ShaderToy shaderToy;
    shaderToy.addTexture(texFiles);
    shaderToy.addUserFragmentMainCode(shaderSource);
    shaderToy.run();

    delete[] shaderSource;

    SDL_Quit();
    return 0;
}

void printUsage()
{
    fprintf(stdout, "Usage: -shader <shader.frag> -channels <channel1.png> <channel2.png> ....");
}
