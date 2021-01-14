
#include "Movement.h"
#include <iostream>
#include <cmath>


movement::movement()
{};

void movement::defineMovement(gameBoard& board, sf::Sprite& circle, const sf::Vector2f& object)
{
    auto window = board.returnSizeOfWindow();
    //conditions for reaching the end of screen
    if(object.x > window.x)
    {
        circle.setPosition(0, object.y);
    }

    if(object.x < 0)
    {
        circle.setPosition(window.x, object.y);
    }

    if(object.y < 0)
    {
        circle.setPosition(object.x, window.y);
    }

    if(object.y > window.y)
    {
        circle.setPosition(object.x, 0);
    }
}

bool movement::leftwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject)
{

    for(auto i = 0; i < posBorder.size(); i++)
    {
        if((int)(posOfObject.left + posOfObject.width) == (int)(posBorder.at(i).left/2) && ((int)(posOfObject.top + posOfObject.height) > (int)posBorder.at(i).top/2) && ((int)posOfObject.top < (int)(posBorder.at(i).top/2 + posBorder.at(i).height)))
            return true;

        else if((int)(posOfObject.left + posOfObject.width) == (int)(posBorder.at(i).left/2 + posBorder.at(i).width)&& ((int)posOfObject.top >= (int)posBorder.at(i).top/2) && ((int)(posOfObject.top + posOfObject.height) <= (int)(posBorder.at(i).top/2 + posBorder.at(i).height)))
        {
            return true;
        }
    }

    return false;
}

bool movement::rightwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject)
{
    for(auto i = 0; i < posBorder.size(); i++)
    {
        if((int)(posOfObject.left) == (int)(posBorder.at(i).left/2 + posBorder.at(i).width) && ((int)(posOfObject.top + posOfObject.height) > (int)posBorder.at(i).top/2) && ((int)posOfObject.top < (int)(posBorder.at(i).top/2 + posBorder.at(i).height)))
        {
            return true;
        }

        else if((int)(posOfObject.left) == (int)(posBorder.at(i).left/2) && ((int)posOfObject.top >= (int)posBorder.at(i).top/2) && ((int)(posOfObject.top + posOfObject.height) <= (int)(posBorder.at(i).top/2 + posBorder.at(i).height)))
        {
            return true;
        }

    }

    return false;
}

bool movement::upwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject)
{
    for(auto i = 0; i < posBorder.size(); i++)
    {
        if((int)(posOfObject.top) == (int)(posBorder.at(i).top/2+posBorder.at(i).height) && ((int)posBorder.at(i).left/2 < (int)(posOfObject.left + posOfObject.width)) && ((int)posOfObject.left < (int)(posBorder.at(i).left/2 + posBorder.at(i).width)))
        {
            return true;
        }

        else if((int)(posOfObject.top) == (int)(posBorder.at(i).top/2) && ((int)posBorder.at(i).left/2 <= (int)posOfObject.left) && ((int)(posOfObject.left +posOfObject.width) <= (int)(posBorder.at(i).left/2 + posBorder.at(i).width)))
        {
            return true;
        }
    }

    return false;
}

bool movement::downwallBlock(gameBoard& board, const vector<sf::FloatRect>&posBorder, const sf::FloatRect& posOfObject)
{

    for(auto i = 0; i < posBorder.size(); i++)
    {
        if((int)(posOfObject.top + posOfObject.height) == (int)(posBorder.at(i).top/2) && ((int)posBorder.at(i).left/2 <= (int)(posOfObject.left + posOfObject.width)) && ((int)(posOfObject.left ) < (int)(posBorder.at(i).left/2 + posBorder.at(i).width)))
            return true;

        else if((int)(posOfObject.top + posOfObject.height) == (int)(posBorder.at(i).top/2 + posBorder.at(i).height)&& ((int)posBorder.at(i).left/2 <= (int)posOfObject.left) && ((int)(posOfObject.left + posOfObject.width) <= (int)(posBorder.at(i).left/2 + posBorder.at(i).width)))
        {
            return true;
        }
    }
    return false;
}

bool movement::moveThroughOpenWall(const int& index, const vector<vector<sf::FloatRect>>&posOpenBorder, const sf::FloatRect& posOfObject)
{

    if((int)(posOfObject.left) <= (int)(posOpenBorder.at(index).at(1).left/2 + posOpenBorder.at(index).at(1).width) &&((int)(posOfObject.left + posOfObject.width) > (int)(posOpenBorder.at(index).at(1).left/2)) && ((int)(posOfObject.top ) > (int)posOpenBorder.at(index).at(1).top/2) && ((int)(posOfObject.top + posOfObject.height) < (int)(posOpenBorder.at(index).at(1).top/2 + posOpenBorder.at(index).at(1).height)))
    {
        return true;
    }

    else if((int)(posOfObject.left) <= (int)(posOpenBorder.at(index).at(0).left/2 + posOpenBorder.at(index).at(0).width) &&((int)(posOfObject.left + posOfObject.width) > (int)(posOpenBorder.at(index).at(0).left/2)) && ((int)(posOfObject.top ) > (int)posOpenBorder.at(index).at(0).top/2) && ((int)(posOfObject.top + posOfObject.height) < (int)(posOpenBorder.at(index).at(0).top/2 + posOpenBorder.at(index).at(0).height)))
    {
        return true;
    }

    return false;

}
