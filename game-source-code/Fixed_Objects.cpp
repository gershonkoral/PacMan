#include "Fixed_Objects.h"
#include <string>
#include <iostream>

fixed_objects::fixed_objects()
{
    if(!KeyTexture.loadFromFile("resources/key.png")|| !FruitTexture.loadFromFile("resources/fruit.png"))
    {
        throw -1;
    }
    KeySprite.setTexture(KeyTexture);
    KeySprite.setColor(sf::Color(255, 215, 0));

    FruitSprite.setTexture(FruitTexture);
    FruitSprite.setColor(sf::Color(255,0,0));
}

void fixed_objects::drawKey(sf::RenderWindow &window)
{
    window.draw(KeySprite);
}

void fixed_objects::drawFruit(sf::RenderWindow &window)
{
    window.draw(FruitSprite);
}

sf::Sprite fixed_objects::createFruit(const int& x, const int& y)
{
    FruitSprite.setPosition(x, y);

    return FruitSprite;
}

sf::Sprite fixed_objects::createKey(const int& x, const int& y)
{

    KeySprite.setPosition(x, y);

    return KeySprite;
}

sf::FloatRect fixed_objects::returnBoundingRect()
{
    return KeySprite.getGlobalBounds();
}

sf::FloatRect fixed_objects::returnBoundingFruitRect()
{
    return FruitSprite.getGlobalBounds();
}


