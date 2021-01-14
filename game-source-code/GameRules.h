#ifndef GAMERULES_H_INCLUDED
#define GAMERULES_H_INCLUDED
/**
*\file GameRules.h
*/
#include <string>
#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace std;


/**
 * @class game_rules
 * @brief This class is responsible for handling the rules and conditions of the game.
 */
class game_rules
{
public:
    /**
     * @brief initializes the font used for all screen messages
     * @param myfont
     */
    game_rules(string myfont);
    /**\fn virtual void drawLivesMessage(int& currentLives, sf::RenderWindow &window);
     * @brief function to draw the number of lives remaining message
     * @param currentLives
     * @param window
     */
    virtual void drawLivesMessage(int& currentLives, sf::RenderWindow &window);
    /**\fn virtual void drawLoseMessage(int& currentLives, sf::RenderWindow &window);
     * @brief function to draw the gameover message if the player loses
     */
    virtual void drawLoseMessage(int& currentLives, sf::RenderWindow &window);
    /**\fn  virtual void drawWinMessage(sf::RenderWindow &window);
     * @brief function to draw the winning message
     */
    virtual void drawWinMessage(sf::RenderWindow &window);
    /**\fn  virtual void drawStartMessage(sf::RenderWindow &window);
    * @brief function to draw the splash screen to start a game
    */
    virtual void drawStartMessage(sf::RenderWindow &window);
    /**\fn virtual void drawScoreMessage( int& currentscore, sf::RenderWindow &window);
    * @brief function to draw the score message
    * @param currentscore
    */
    virtual void drawScoreMessage( int& currentscore, sf::RenderWindow &window);
    /**\fn  virtual bool PacEatsPowerPellet(sprites& pac);
    * @brief function to handle the logic of the collision between Pac-Man and Power Pellet
    * @param pac
    */
    virtual bool PacEatsPowerPellet(sprites& pac);
    /**\fn  virtual void updateGameforPowerPellet(sprites& spr);
     * @brief function to return ghosts to the center box if eaten while Pac-Man has an active Power Pellet
     * @param spr
     */
    virtual void updateGameforPowerPellet(sprites& spr);
    /**\fn virtual void normalConditions(sprites& spr);
    * @brief function to revert to normal blue Ghost conditions
    * @param spr
    */
    virtual void normalConditions(sprites& spr);
    /**\fn virtual tuple<int, bool> KeyCollision(sprites& pac, const vector<sf::FloatRect> &KEYS) const;
     * @brief function to handle logic of key collisions
     * @param pac
     * @param KEYS
     */
    virtual tuple<int, bool> KeyCollision(sprites& pac, const vector<sf::FloatRect> &KEYS) const;
    /**\fn virtual tuple<int, bool> FruitCollision1(sprites& pac, const vector<sf::FloatRect> &FRUIT) const;
     * @brief function to handle logic of fruit collisions
     * @param pac
     * @param KEYS
     */
    virtual tuple<int, bool> FruitCollision1(sprites& pac, const vector<sf::FloatRect> &FRUIT) const;


private:

    sf::Font font1;
    sf::Texture text;
    sf::Sprite background;
    sf::Clock clock;

    sf::Text LivesMessage_;
    sf::Text StartMessage;
    sf::Text ScoreMessage;
    sf::Text LoseMessage;
    sf::Text WinMessage;

    int local_class_check;
};

#endif // GAMERULES_H_INCLUDED
