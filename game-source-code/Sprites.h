
#ifndef Sprites_h
#define Sprites_h

/**
*\file Sprites.h
*/
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;


/**
 * @class sprites
 * @brief This class is responsible for constructing and tracking Pac-Man, the Ghosts and the power pellets
 */
class sprites
{
public:
    /**
    * @brief Construct and position Pac-Man, the four Ghosts and the two power pellets.
    * @param circle
    * @param imagPac
    * @param imagghost
    */
    sprites(const sf::Sprite circle, string imagPac, string imagghost);

    /**\fn sf::Vector2f returnPosOfPac();
    * \return current position of Pac-Man.
    */
    sf::Vector2f returnPosOfPac();
    /**\fn sf::Vector2f returnPosOfGhost();
    * \return current position of Ghost 1.
    */
    sf::Vector2f returnPosOfGhost();
    /**\fn sf::Vector2f returnPosOfGhost2()
    * \return current position of Ghost 2.
    */
    sf::Vector2f returnPosOfGhost2();
    /**\fn sf::Vector2f returnPosOfGhost3()
    * \return current position of Ghost 3.
    */
    sf::Vector2f returnPosOfGhost3();
    /**\fn sf::Vector2f returnPosOfGhost4()
    * \return current position of Ghost 4.
    */
    sf::Vector2f returnPosOfGhost4();
    /**\fn drawSprites(sf::RenderWindow &window)
    * @brief function to draw Pac-Man, the four Ghosts and the 2 Power Pellets.
    */
    void drawSprites(sf::RenderWindow &window);

    /**
     * @brief pacman sprite
     */
    sf::Sprite pacman;
    /**
     * @brief Ghost 1 sprite
     */
    sf::Sprite GhostSprite;
    /**
     * @brief Ghost 2 sprite
     */
    sf::Sprite GhostSprite2;
    /**
     * @brief Ghost 3 sprite
     */
    sf::Sprite GhostSprite3;
    /**
     * @brief Ghost 4 sprite
     */
    sf::Sprite GhostSprite4;

    /**\fn sf::FloatRect return_border_pac();
    * \return bounding rectangle around Pac-Man.
    */
    sf::FloatRect return_border_pac();
    /**\fn sf::FloatRect return_border_ghost();
    * \return bounding rectangle around Ghost.
    */
    sf::FloatRect return_border_ghost();
    /**\fn sf::FloatRect return_border_ghost2();
    * \return bounding rectangle around Ghost 2.
    */
    sf::FloatRect return_border_ghost2();
    /**\fn sf::FloatRect return_border_ghost3();
    * \return bounding rectangle around Ghost 3.
    */
    sf::FloatRect return_border_ghost3();
    /**\fn sf::FloatRect return_border_ghost4();
    * \return bounding rectangle around Ghost4
    */
    sf::FloatRect return_border_ghost4();
    /**\fn vector<sf::FloatRect> return_border_powerPellet();
       * \return bounding rectangle around Power Pellets.
       */
    vector<sf::FloatRect> return_border_powerPellet();
    /**\fn updatePowerPellet(const int& index);
        * @brief function to delete a Power Pellet once eaten and change the Ghost colour to red.
        * @param index
        */
    void updatePowerPellet(const int& index);
    /**\fn updatePacman();
        * @brief function to respawn Pac-Man after colliding with a Ghost
        */
    void updatePacman();

private:
    vector<unique_ptr<sf::CircleShape>>power_pellets;
    sf::Texture ghosttexture;
    sf::Texture pactexture;

};

#endif /* Sprites_h */
