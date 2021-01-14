
#ifndef GamePlay_h
#define GamePlay_h

/**
*\file GamePlay.h
*/
#include "Fixed_Objects.h"
#include "GameRules.h"
#include "Movement.h"
#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

/**
 * @class GamePlay
 * @brief This derived class links the presentation and logic layers of the other classes. It is the main class that allows the game to run.
 */
class GamePlay: public game_rules, public movement
{
public:
    /**
     * @brief Initialise the game
     * @param board_
     * @param object
     * @param window
     * @param keys_fruit
     */
    GamePlay( gameBoard& board_, sprites& object, sf::RenderWindow& window, fixed_objects& keys_fruit);
    /**\fn void movePacman( const int& x, const int& y);
    * @brief function to move Pac-Man in a specific direction
    * @param x
    * @param y
    */
    void movePacman( const int& x, const int& y);
    /**\fn void collision(gameBoard& board, int& currentLives, bool& isPlaying, bool& winner);
     * @brief function to handle all collisions and their consequences
     * @param currentLives
     * @param isPlaying
     * @param winner
     */
    void collision(gameBoard& board, int& currentLives, bool& isPlaying, bool& winner);
    /**\fn void drawAllObjects();
        * @brief function to draw all objects in the game
        */
    void drawAllObjects();
    /**\fn tuple<int, int>KeyPressed(sf::RenderWindow& window, sf::Event event);
        * @brief function to handle user-input
        * @param event
        */
    tuple<int, int>KeyPressed(sf::RenderWindow& window, sf::Event event);
    /**\fn void moveGhost();
        * @brief function to move all four ghosts
        */
    void moveGhost();
    /**\fn void gameLoop();
        * @brief main game loop function
        */
    void gameLoop();

private:
    sprites& object_;
    gameBoard& board;
    sf::RenderWindow& window_;
    fixed_objects& keys_fruit_;

    int x_speed, y_speed;
    bool coll;
    bool lostlife, isPlaying, winner = false;
    int currentScore = 0;
    int currentLives = 3;
    int ghostmovx, ghostmovy, ghost2movx, ghost2movy, ghost3movx, ghost3movy, ghost4movx, ghost4movy;
    int fruiteaten = 0;
    int randNum, randNum2;
    bool firstdir = true;

    vector<int>storePreviousKeyHits{};
    vector<int>storePreviousFruitHits{};

    sf::SoundBuffer buffer;
    sf::Sound chomp;

    sf::Clock clock;

    bool check1, check2, check3, allowEntry = false;

    void vectorMaths(vector<int>&vec, const int& para);


};

#endif /* GamePlay_hpp */
