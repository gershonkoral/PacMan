
#include "Sprites.h"
#include <string>
#include <iostream>

sprites::sprites(const sf::Sprite circle, string imagPac, string imagghost): pacman{circle}
{
    if(!ghosttexture.loadFromFile(imagghost))
    {
        throw -1;
    }

    if(!pactexture.loadFromFile(imagPac))
    {
        throw -1;
    }


    pacman.setTexture(pactexture);
    pacman.setScale(0.15, 0.15);
    pacman.setPosition(775, 550); //starting position

    GhostSprite.setTexture(ghosttexture);
    GhostSprite.setPosition(780, 400);

    GhostSprite2.setTexture(ghosttexture);
    GhostSprite2.setPosition(780, 415);

    GhostSprite3.setTexture(ghosttexture);
    GhostSprite3.setPosition(750, 415);

    GhostSprite4.setTexture(ghosttexture);
    GhostSprite4.setPosition(750, 415);

    power_pellets.push_back(unique_ptr<sf::CircleShape>(new sf::CircleShape));
    power_pellets.push_back(unique_ptr<sf::CircleShape>(new sf::CircleShape));

    power_pellets.at(0)->setRadius(20);
    power_pellets.at(0)->setPosition(710, 625);
    power_pellets.at(0)->setFillColor(sf::Color(190, 110, 128));
    power_pellets.at(1)->setRadius(20);
    power_pellets.at(1)->setPosition(844, 625);
    power_pellets.at(1)->setFillColor(sf::Color(190, 110, 128));

}

// returns actual x-y coords of pacman
sf::Vector2f sprites::returnPosOfPac()
{
    return pacman.getPosition();
}

sf::Vector2f sprites::returnPosOfGhost()
{
    return GhostSprite.getPosition();
}

sf::Vector2f sprites::returnPosOfGhost2()
{
    return GhostSprite2.getPosition();
}

sf::Vector2f sprites::returnPosOfGhost3()
{
    return GhostSprite3.getPosition();
}

sf::Vector2f sprites::returnPosOfGhost4()
{
    return GhostSprite4.getPosition();
}

// returns bounding rectangle around pacman
sf::FloatRect sprites::return_border_pac()
{
    return pacman.getGlobalBounds();
}

sf::FloatRect sprites::return_border_ghost()
{
    return GhostSprite.getGlobalBounds();
}

vector<sf::FloatRect> sprites::return_border_powerPellet()
{

    vector<sf::FloatRect>store;

    for(auto i = 0; i < power_pellets.size(); i++)
    {
        if(power_pellets.at(i) != nullptr)
        {
            store.push_back(power_pellets.at(i)->getGlobalBounds());
        }

    }
    if(store.empty())
    {
        vector<sf::FloatRect>dummy;
        return dummy;
    }

    return store;

}

sf::FloatRect sprites::return_border_ghost2()
{
    return GhostSprite2.getGlobalBounds();
}

sf::FloatRect sprites::return_border_ghost3()
{
    return GhostSprite3.getGlobalBounds();
}

sf::FloatRect sprites::return_border_ghost4()
{
    return GhostSprite4.getGlobalBounds();
}

void sprites::drawSprites(sf::RenderWindow &window)
{
    window.draw(pacman);
    window.draw(GhostSprite);
    window.draw(GhostSprite2);
    window.draw(GhostSprite3);
    window.draw(GhostSprite4);

    for(auto i = 0; i < power_pellets.size(); i++)
    {
        if(power_pellets.at(i) != nullptr)
        {
            window.draw(*power_pellets.at(i));
        }
    }

}

void sprites::updatePowerPellet(const int& index)
{
    power_pellets.at(index) = nullptr;

    GhostSprite.setColor(sf::Color::Red);
    GhostSprite2.setColor(sf::Color::Red);
    GhostSprite3.setColor(sf::Color::Red);
    GhostSprite4.setColor(sf::Color::Red);
}

void sprites::updatePacman()
{
    pacman.setPosition(775, 550);
    pacman.move(0, 0);
}


