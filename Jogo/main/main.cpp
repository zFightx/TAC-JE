#include <iostream>

#include "../header/engine/Game.h"

int main (int argc, char** argv){
    Game &instance = Game::GetInstance();

    instance.GetState().LoadAssets();
    instance.Run();

    std::cout << SDL_GetError();
    std::cout << "Encerrando Jogo..." << endl;
    std::cout << "Pressione qualquer tecla para encerrar...";
    getchar();
    return 0;
}