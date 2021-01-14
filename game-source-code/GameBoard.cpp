
#include "GameBoard.h"
#include <vector>
#include <string>

gameBoard::gameBoard(const sf::RectangleShape& border, sf::RenderWindow& window, string inFile): border_{border}, window_(window), inFile_{inFile}
{
    border_.setFillColor(sf::Color::Transparent);;
    border_.setOutlineColor(sf::Color::Cyan);
    border_.setOutlineThickness(3);

    storeOpenBorderPosition = {690, 398, 894, 398, 0, 412, 1590, 412, 55, 108, 313, 108, 1270, 108, 1526, 108, 374, 108, 1212, 108, 55, 420, 315, 420, 1270, 420, 1526, 420, 374, 420, 631, 420, 374, 247, 631, 247, 374, 604, 631, 604, 691, 604, 761, 604, 826, 604, 896, 604, 951, 604, 1211, 604, 951, 421, 1211, 421, 951, 247, 1211, 247, 55, 740, 313, 740, 374, 740, 1211, 740, 1270, 740, 1526, 740};

    openBorder.setFillColor(sf::Color::Yellow);

    clock.restart();

    windowSize = window_.getSize();
    sf::Vector2f reSizeWindow(windowSize.x, windowSize.y);

    for(auto i = 0; i < 18; i++)
    {
        KEYS.push_back(unique_ptr<fixed_objects>(new fixed_objects()));
    }

    (KEYS.at(0)->createKey(0, 50));
    (KEYS.at(1)->createKey(1525, 50));
    (KEYS.at(2)->createKey(0, 810));
    (KEYS.at(3)->createKey(1525, 810));
    (KEYS.at(4)->createKey(1210, 270));
    (KEYS.at(5)->createKey(1210, 680));
    (KEYS.at(6)->createKey(895, 430));
    (KEYS.at(7)->createKey(762, 232));
    (KEYS.at(8)->createKey(762, 610));
    (KEYS.at(9)->createKey(630, 430));
    (KEYS.at(10)->createKey(310, 322));
    (KEYS.at(11)->createKey(310, 610));
    (KEYS.at(12)->createKey(790, 40));
    (KEYS.at(13)->createKey(790, 815));
    (KEYS.at(14)->createKey(0, 420));
    (KEYS.at(15)->createKey(1525, 420));
    (KEYS.at(16)->createKey(170, 180));
    (KEYS.at(17)->createKey(170, 675));


    for(auto i = 0; i < 76; i++)
    {
        FRUIT.push_back(unique_ptr<fixed_objects>(new fixed_objects()));
    }

    (FRUIT.at(0)->createFruit(388,124 ));
    (FRUIT.at(1)->createFruit(498,124 ));
    (FRUIT.at(2)->createFruit(608,124 ));
    (FRUIT.at(3)->createFruit(718,124));
    (FRUIT.at(4)->createFruit(828,124 ));
    (FRUIT.at(5)->createFruit(938,124 ));
    (FRUIT.at(6)->createFruit(1048,124));
    (FRUIT.at(7)->createFruit(1158,124 ));
    (FRUIT.at(8)->createFruit(388,760 ));
    (FRUIT.at(9)->createFruit(498, 760));
    (FRUIT.at(10)->createFruit(608, 760));
    (FRUIT.at(11)->createFruit(718, 760));
    (FRUIT.at(12)->createFruit(828, 760));
    (FRUIT.at(13)->createFruit(938, 760));
    (FRUIT.at(14)->createFruit(1048, 760));
    (FRUIT.at(15)->createFruit(1158, 760));
    (FRUIT.at(16)->createFruit(70,124 ));
    (FRUIT.at(17)->createFruit(160,124 ));
    (FRUIT.at(18)->createFruit(250,124 ));
    (FRUIT.at(19)->createFruit(1284,124 ));
    (FRUIT.at(20)->createFruit(1374,124 ));
    (FRUIT.at(21)->createFruit(1464,124 ));
    (FRUIT.at(22)->createFruit(70,760 ));
    (FRUIT.at(23)->createFruit(160,760 ));
    (FRUIT.at(24)->createFruit(250,760 ));
    (FRUIT.at(25)->createFruit(1284,760 ));
    (FRUIT.at(26)->createFruit(1374,760 ));
    (FRUIT.at(27)->createFruit(1464,760 ));
    (FRUIT.at(28)->createFruit(70,257 ));
    (FRUIT.at(29)->createFruit(160,257 ));
    (FRUIT.at(30)->createFruit(250,477 ));
    (FRUIT.at(31)->createFruit(70,587 ));
    (FRUIT.at(32)->createFruit(160,587 ));
    (FRUIT.at(33)->createFruit(250,587 ));
    (FRUIT.at(34)->createFruit(1284,257 ));
    (FRUIT.at(35)->createFruit(1374,257 ));
    (FRUIT.at(36)->createFruit(1464,257 ));
    (FRUIT.at(37)->createFruit(1284,367 ));
    (FRUIT.at(38)->createFruit(1374,367 ));
    (FRUIT.at(39)->createFruit(1464,367 ));
    (FRUIT.at(40)->createFruit(1284,477 ));
    (FRUIT.at(41)->createFruit(1374,477 ));
    (FRUIT.at(42)->createFruit(1464,477 ));
    (FRUIT.at(43)->createFruit(1284,587 ));
    (FRUIT.at(44)->createFruit(1374,587 ));
    (FRUIT.at(45)->createFruit(1464,587 ));
    (FRUIT.at(46)->createFruit(388, 620));
    (FRUIT.at(47)->createFruit(478, 620));
    (FRUIT.at(48)->createFruit(568, 620));
    (FRUIT.at(49)->createFruit(388, 477));
    (FRUIT.at(50)->createFruit(478, 477));
    (FRUIT.at(51)->createFruit(568, 477));
    (FRUIT.at(52)->createFruit(388, 397));
    (FRUIT.at(53)->createFruit(478, 397));
    (FRUIT.at(54)->createFruit(568, 397));
    (FRUIT.at(55)->createFruit(388, 257));
    (FRUIT.at(56)->createFruit(478, 257));
    (FRUIT.at(57)->createFruit(568, 257));
    (FRUIT.at(58)->createFruit(970,257 ));
    (FRUIT.at(59)->createFruit(1060,257 ));
    (FRUIT.at(60)->createFruit(1150,257 ));
    (FRUIT.at(61)->createFruit(970,477 ));
    (FRUIT.at(62)->createFruit(1060, 477));
    (FRUIT.at(63)->createFruit(1150, 477));
    (FRUIT.at(64)->createFruit(970, 397));
    (FRUIT.at(65)->createFruit(1060, 397));
    (FRUIT.at(66)->createFruit(1150, 397));
    (FRUIT.at(67)->createFruit(970, 620));
    (FRUIT.at(68)->createFruit(1060, 620));
    (FRUIT.at(69)->createFruit(1150, 620));
    (FRUIT.at(70)->createFruit(250,257 ));
    (FRUIT.at(71)->createFruit(70,367 ));
    (FRUIT.at(72)->createFruit(160,367) );
    (FRUIT.at(73)->createFruit(250,367 ));
    (FRUIT.at(74)->createFruit(70,477 ));
    (FRUIT.at(75)->createFruit(160,477 ));

}

void gameBoard::readInBorders()
{
    std::ifstream inFile(inFile_);

    if(!inFile)
        throw EXIT_FAILURE;

    int input = 0;
    int count = 0;

    while(inFile >> input)
    {
        storeBorderPosition.push_back(input);

        if(count % 2 != 0 && count <= storeOpenBorderPosition.size())
        {
            openBorder.setPosition(storeOpenBorderPosition.at(count-1), storeOpenBorderPosition.at(count));
            openBorder.setSize(sf::Vector2f(10, 78));
            rectopenBorderPos.push_back(openBorder);

        }

        if(count ==3 || count % 4 == 3) //push into container once at the end of file line
        {
            border_.setPosition(storeBorderPosition.at(count-3), storeBorderPosition.at(count-2));
            border_.setSize(sf::Vector2f(storeBorderPosition.at(count-1), storeBorderPosition.at(count)));
            rectBorderPosition.push_back(border_);
        }
        count++;
    }

    inFile.close();

    //Vector rearrangement into a 2D vector
    while(rectopenBorderPos.size() >= 2)
    {
        openBorderPair.push_back(rectopenBorderPos);
        rectopenBorderPos.pop_back();
        rectopenBorderPos.pop_back();
    }

    for(int i = 0; i < openBorderPair.size(); i++)
    {
        openBorderPair.at(i).erase(openBorderPair.at(i).begin(), openBorderPair.at(i).end()-2);
    }

    rectopenBorderPos.clear(); //free up memory
    storeOpenBorderPosition.clear();
    storeBorderPosition.clear();
    reverse(openBorderPair.begin(), openBorderPair.end());
}

void gameBoard::drawBorders()
{
    auto elapsedTime = clock.getElapsedTime().asMilliseconds();

    for(auto i = 0; i < rectBorderPosition.size(); i++)
    {
        window_.draw(rectBorderPosition.at(i));
    }

    for(auto i = 0; i < openBorderPair.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            openBorderPair.at(0).at(j).setFillColor(sf::Color(elapsedTime%256, 50,220));
            window_.draw(openBorderPair.at(i).at(j));
        }
    }

    for(auto i = 0; i <KEYS.size(); i++)
    {
        if(KEYS.at(i) != nullptr)
        {
            KEYS.at(i)->drawKey(window_);
        }
    }

    for(auto i = 0; i <FRUIT.size(); i++)
    {
        if(FRUIT.at(i) != nullptr)
        {
            FRUIT.at(i)->drawFruit(window_);
        }
    }
}

vector<sf::FloatRect>gameBoard::return_RectkeyObj()
{
    vector<sf::FloatRect>temp{};

    for(auto i = 0; i < KEYS.size(); i++)
    {
        if(KEYS.at(i) != nullptr)
        {
            temp.push_back(KEYS.at(i)->returnBoundingRect());
        }

        else
        {
            sf::FloatRect empty;
            temp.push_back(empty);
        }
    }

    return temp;
}

vector<sf::FloatRect>gameBoard::return_RectfruitObj()
{
    vector<sf::FloatRect>temp{};

    for(auto i = 0; i < FRUIT.size(); i++)
    {
        if(FRUIT.at(i) != nullptr)
        {
            temp.push_back(FRUIT.at(i)->returnBoundingFruitRect());
        }

        else
        {
            sf::FloatRect empty;
            temp.push_back(empty);
        }
    }
    return temp;
}

vector<sf::FloatRect>gameBoard::returnBorderPos()
{

    std::vector<sf::FloatRect>conversion{};

    for(auto i = 0; i < rectBorderPosition.size(); i++)
    {
        auto a = rectBorderPosition.at(i).getTransform();
        auto b = a.transformRect(rectBorderPosition.at(i).getGlobalBounds());
        conversion.push_back(b);
    }
    return conversion;
}


vector<vector<sf::FloatRect>>gameBoard::returnOpenBorderPos()
{
    vector<vector<sf::FloatRect>>conversion{};
    vector<sf::FloatRect>temp{};

    for(auto i = 0; i < openBorderPair.size(); i++)
    {
        for(auto j = 0; j < 2; j++)
        {
            temp.push_back(openBorderPair.at(i).at(j).getTransform().transformRect(openBorderPair.at(i).at(j).getGlobalBounds()));
        }
        conversion.push_back(temp);
        temp.clear();
    }
    return conversion;
}


sf::Vector2<unsigned int> gameBoard::returnSizeOfWindow()
{
    return windowSize;
}

void gameBoard::updateGameBoard(const int& vectorIndex)
{
    openBorderPair.at(vectorIndex).at(0).setFillColor(sf::Color::Black);
    openBorderPair.at(vectorIndex).at(1).setFillColor(sf::Color::Black);
}


