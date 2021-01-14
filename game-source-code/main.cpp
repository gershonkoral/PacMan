
#include "GamePlay.h"
#include "GameRules.cpp"
int main()
{
    sf::Sprite Pacman, ghost;
    sf::RectangleShape border;
    sf::RenderWindow window;

    auto objects_ = fixed_objects{};

    auto sprite = sprites{Pacman, "resources/pacmansprite.png", "resources/ghost.png"}; // Allows the client to choose their own textures for Pacman and ghosts
    auto board = gameBoard{border, window, "resources/PacmanMaze.txt"}; // Allows for the client to read his/her own maze structure into the game
    auto game = GamePlay(board, sprite, window, objects_);

    game.gameLoop();

    return EXIT_SUCCESS;
}

