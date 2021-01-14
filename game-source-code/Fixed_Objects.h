#ifndef FIXED_OBJECTS_H_INCLUDED
#define FIXED_OBJECTS_H_INCLUDED

/**
*\file Fixed_Objects.h
*/
#include <string>
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;


/**
 * @class fixed_objects
 * @brief This class is responsible for constructing the fruit and key fixed objects
 */
class fixed_objects
{
public:
    /**
    * @brief Initializes the key and fruit texture
    */
    fixed_objects();
    /**\fn  void drawKey(sf::RenderWindow &window);
     * @brief function to draw key
     * @param window
     */
    void drawKey(sf::RenderWindow &window);
    /**\fn void drawFruit(sf::RenderWindow &window);
     * @brief function to draw fruit
     * @param window
     */
    void drawFruit(sf::RenderWindow &window);
    /**\fn sf::Sprite createFruit(const int& x, const int& y);
     * @brief function to create fruit in a specific location
     * @param x
     * @param y
     */
    sf::Sprite createFruit(const int& x, const int& y);
    /**\fn sf::Sprite createKey(const int& x, const int& y);
     * @brief function to draw key in specific location
     */
    sf::Sprite createKey(const int& x, const int& y);
    /**\fn  sf::FloatRect returnBoundingRect();
     * @brief function to return bounding rectangle around key
     */
    sf::FloatRect returnBoundingRect();
    /**\fn  sf::FloatRect returnBoundingFruitRect();
     * @brief function to return bounding rectangle around fruit
     */
    sf::FloatRect returnBoundingFruitRect();

private:

    sf::Sprite KeySprite;
    sf::Sprite FruitSprite;
    sf::Texture KeyTexture;
    sf::Texture FruitTexture;
};

#endif // FIXED_OBJECTS_H_INCLUDED
