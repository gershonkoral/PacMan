

#ifndef Movement_h
#define Movement_h

/**
*\file Movement.h
*/
#include "GameBoard.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;


/**
 * @class movement
 * @brief This class is responsible for all game movement conditions
 */
class movement
{

public:
    /**
     * @brief default constructor
     */
    movement();
    /**\fn virtual void defineMovement(gameBoard& board, sf::Sprite& circle, const sf::Vector2f& object);
     * @brief function to deal with movement through the screen walls
     * @param board
     * @param circle
     * @param object
     */
    virtual void defineMovement(gameBoard& board, sf::Sprite& circle, const sf::Vector2f& object);

    /**\fn  virtual bool leftwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
     * @brief function to handle a generic left wall block
     * @param posBorder
     * @param posOfObject
     */
    virtual bool leftwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    /**\fn  virtual bool rightwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    * @brief function to handle a generic right wall block
    */
    virtual bool rightwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    /**\fn virtual bool upwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    * @brief function to handle a generic up wall block
    */
    virtual bool upwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    /**\fn  virtual bool downwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    * @brief function to handle a generic down wall block
    */
    virtual bool downwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject);
    /**\fn virtual bool moveThroughOpenWall(const int& index, const vector<vector<sf::FloatRect>>&posOpenBorder, const sf::FloatRect& posOfObject);
    * @brief function to allow/restrict sprites to move through doors of the maze
    * @param index
    * @param posOpenBorder
    */
    virtual bool moveThroughOpenWall(const int& index, const vector<vector<sf::FloatRect>>&posOpenBorder, const sf::FloatRect& posOfObject);

private:

    int x_coord;
    int y_coord;
    bool insideBorder;
};

#endif
