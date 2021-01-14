

#ifndef GameBoard_h
#define GameBoard_h

/**
*\file GameBoard.h
*/
#include <SFML/Graphics.hpp>
#include "Fixed_Objects.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


/**
 * @class gameBoard
 * @brief This class is responsible for constructing and tracking the current game-board
 */
class gameBoard
{
public:
    /**
       * @brief Create and Initialise the starting game maze with all objects
       * @param boarder
       * @param window
       * @param inFile
       */
    gameBoard(const sf::RectangleShape& border, sf::RenderWindow& window, string inFile);
    /**\fn void drawBorders();
    * @brief function to draw locked sections, open sections, keys, fruit
    */
    void drawBorders();
    /**\fn  void readInBorders();
     * @brief function to read in and store maze from a file
     */
    void readInBorders();
    /**\fn  vector<sf::FloatRect>returnBorderPos();
     * @brief function to transform border positions to a 2D vector
     */
    vector<sf::FloatRect>returnBorderPos();
    /**\fn  vector<vector<sf::FloatRect>>returnOpenBorderPos();
    * @brief function to transform open border positions to a 2D vector
    */
    vector<vector<sf::FloatRect>>returnOpenBorderPos();
    /**\fn  vector<sf::FloatRect>return_RectkeyObj();
    * @brief function to return bounded key object
    */
    vector<sf::FloatRect>return_RectkeyObj();
    /**\fn vector<sf::FloatRect>return_RectfruitObj();
     * @brief function to return bounded fruit object
     */
    vector<sf::FloatRect>return_RectfruitObj();
    /**\fn  void updateGameBoard(const int& vectorIndex);
    * @brief function to update the state of the open/closed borders in the current gameboard
    * @param vectorIndex
    */
    void updateGameBoard(const int& vectorIndex);
    /**\fn sf::Vector2<unsigned int> returnSizeOfWindow();
    * @brief function to return the size of the game window
    */
    sf::Vector2<unsigned int> returnSizeOfWindow();
    /**
    * @brief 2D public vector storing pointers to keys
    */
    vector<unique_ptr<fixed_objects>>KEYS;
    /**
     * @brief 2D public vector storing pointers to Fruit
     */
    vector<unique_ptr<fixed_objects>>FRUIT;

private:
    sf::RectangleShape openBorder;
    sf::RectangleShape border_;

    string inFile_;

    sf::RenderWindow& window_;
    sf::Vector2<unsigned int>windowSize;

    vector<sf::RectangleShape>rectopenBorderPos{};
    vector<vector<sf::RectangleShape>>openBorderPair; //main open border position vector

    vector<sf::RectangleShape>rectBorderPosition{};

    vector<int>storeBorderPosition{};
    vector<int>storeOpenBorderPosition{};

    sf::Clock clock;
};

#endif /* GameBoard_h */
