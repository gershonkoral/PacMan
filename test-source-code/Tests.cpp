#include "../game-source-code/Sprites.h"
#include "../game-source-code/GameBoard.h"
#include "../game-source-code/GamePlay.h"
#include "../game-source-code/Fixed_Objects.h"
#include "../game-source-code/Movement.h"
#include"../game-source-code/GameRules.h"


using namespace std;


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

sf::Sprite Pacman, ghost;
sf::RectangleShape border;
sf::RenderWindow window;

auto objects_ = fixed_objects {}; //load key texture into the game

auto sprite = sprites(Pacman, "resources/pacmansprite.png", "resources/ghost.png");
auto board = gameBoard(border, window, "resources/PacmanMaze.txt");
auto game = GamePlay(board, sprite, window, objects_);
auto movePac = movement();


TEST_CASE("Checking Tests work")
{
    CHECK(1==1) ;
}

TEST_CASE("Pacman is created with default settings position x")
{
    sf::Sprite PM;
    auto sprite = sprites{PM,"resources/pacmansprite.png", "resources/ghost.png"}; // Pacman and ghost constructor
    CHECK(PM.getPosition().x==0.0f);
}

TEST_CASE("Pacman is created with default settings position y")
{
    sf::Sprite PM;

    auto sprite = sprites{PM,"resources/pacmansprite.png", "resources/ghost.png"};
    CHECK(PM.getPosition().y==0.0f);
}

TEST_CASE("Ghost 1 is created with default settings position x")
{
    sf::Sprite PM;
    sprites sprite(PM,"resources/pacmansprite.png", "resources/ghost.png");
    auto a = sprite.GhostSprite.getPosition().x;
    CHECK(a==780.0f);
}

TEST_CASE("Ghost 1 is created with default settings position y")
{
    sf::Sprite PM;
    sprites sprite(PM, "resources/pacmansprite.png","resources/ghost.png");
    auto a = sprite.GhostSprite.getPosition().y;
    CHECK(a==400.0f);
}

TEST_CASE("Ghost 2 is created with default settings position x")
{
    sf::Sprite PM;

    sprites sprite(PM,"resources/pacmansprite.png", "resources/ghost.png");
    auto a = sprite.GhostSprite2.getPosition().x;
    CHECK(a==780.0f);
}

TEST_CASE("Ghost 2 is created with default settings position y")
{
    sf::Sprite PM;
    sprites sprite(PM,"resources/pacmansprite.png", "resources/ghost.png");
    auto a = sprite.GhostSprite.getPosition().y;
    CHECK(a==400.0f);
}

TEST_CASE("Ghosts turn blue after 8 seconds")
{
    sf::Clock clock1;
    int a;
    while ( clock1.getElapsedTime().asSeconds()<8)
    {

    }
    CHECK(sprite.pacman.getColor().b==255);
}

TEST_CASE("PacMan is initialized to starting x position")
{
    sf::Sprite PM;
    sprites sprite(PM,"resources/pacmansprite.png", "resources/ghost.png");
    auto a = sprite.pacman.getPosition().y;
    CHECK(a==550.0f);
}

TEST_CASE("PacMan is initialized to starting y position")
{
    sf::Sprite PM;
    sprites sprite(PM,"resources/pacmansprite.png", "resources/ghost.png");
    auto a = sprite.pacman.getPosition().y;
    CHECK(a==550.0f);
}

TEST_CASE("Pacman moves along the x direction")
{

    auto x_speed = 1;
    auto y_speed = 0;
    auto first_pos = sprite.pacman.getPosition();
    game.movePacman(x_speed, y_speed);
    auto second_pos = sprite.pacman.getPosition();
    CHECK(first_pos.x+1 == second_pos.x);

}

TEST_CASE("Pacman moves down along the y direction")
{

    auto x_speed = 0;
    auto y_speed = 1;
    auto first_pos = sprite.pacman.getPosition();
    game.movePacman(x_speed, y_speed);
    auto second_pos = sprite.pacman.getPosition();
    CHECK(first_pos.y+1 == second_pos.y);
}

TEST_CASE("Ghosts moves down along the x direction")
{

    auto a = sprite.GhostSprite2.getPosition().x;
    game.moveGhost();
    auto b = sprite.GhostSprite2.getPosition().x;

    CHECK(a+1==b);
}

TEST_CASE("Can convert sf::RectangleShape to sf::FloatRect for the borders")
{
    board.readInBorders();
    auto maze_border_1 = board.returnBorderPos();
    auto float_border = maze_border_1.at(4).left;
    CHECK(float_border == (697*2 -3)); //697 is the 5th x-position in the maze file read in. Multiplied by 2

    //since there are double the no. of pixels as positions in the window. There is a -3 shift due to rounding

    //errors in all values. Does not affect the precision of the border positions
}

//Sprite and object collision detection tests

TEST_CASE("Collsision detection between Pacman and ghost")
{
    sprite.pacman.setPosition(780, 415);
    auto a = sprite.return_border_pac().intersects(sprite.return_border_ghost());
    CHECK(a == true);
}

TEST_CASE("Collsision detection between Pacman and Key")
{
    sprite.pacman.setPosition(1, 52);
    auto a = sprite.return_border_pac().intersects(objects_.returnBoundingRect());
    CHECK(a == true);
}

TEST_CASE("Collsision detection between Pacman and fruit")
{
    sprite.pacman.setPosition(70, 120);
    objects_.createFruit(70, 120);
    auto a = sprite.return_border_pac().intersects(objects_.returnBoundingFruitRect());
    CHECK(a == true);
}

TEST_CASE("Pacman respawns upon collision with ghost")
{
    sprite.pacman.setPosition(780, 415);                //Same position as the ghosts
    if(sprite.return_border_pac().intersects(sprite.return_border_ghost()))
    {
        sprite.updatePacman();
    }
    auto b = sprite.pacman.getPosition().x;
    CHECK(b == 775);                        //x position of respawn
}


TEST_CASE("Pacman cannot move through a locked border wall")
{
    sprite.pacman.setPosition(7, 125); //this is the position of a locked wall in the maze
    auto openBorder = board.returnOpenBorderPos();
    auto border = board.returnBorderPos();
    if(!movePac.leftwallBlock(board, border, sprite.pacman.getGlobalBounds()))
    {
        sprite.pacman.move(1, 0);
    }
    auto check = sprite.pacman.getPosition().x;
    CHECK(check == 7);
}

TEST_CASE("Pacman can move through an unlocked open border")
{
    board.updateGameBoard(2);
    sprite.pacman.move(1, 0);
    CHECK(sprite.pacman.getPosition().x == 8);
}

// Wall collisions detetction tests:

TEST_CASE("Collsision with outside top horizontal wall detected")
{
    sprite.pacman.setPosition(100, 48); //along the first (outside) border/perimeter. x is arbitrary, y is 2 fewer than the limit set by maze file (50).
    auto check_bottom = movePac.upwallBlock(board, board.returnBorderPos(), sprite.return_border_pac());
    CHECK(check_bottom == true);
}

TEST_CASE("Collsision with inner left vertical wall detected")
{
    sprite.pacman.setPosition(0, 100);  //along the first (outside) border/perimeter. y is arbitrary, x is 2 fewer than the limit set by maze file (2).
    auto check_bottom = movePac.rightwallBlock(board, board.returnBorderPos(), sprite.return_border_pac());
    CHECK(check_bottom == true);
}

TEST_CASE("Collsision with inner right vertical wall detected")
{
    sprite.pacman.setPosition(1545, 100);
    auto check_bottom = movePac.leftwallBlock(board, board.returnBorderPos(), sprite.return_border_pac());
    CHECK(check_bottom == true);
}

