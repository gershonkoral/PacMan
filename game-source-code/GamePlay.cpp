
#include "GamePlay.h"
#include <iostream>
#include <ctime>

GamePlay::GamePlay(gameBoard& board_,  sprites& object, sf::RenderWindow& window, fixed_objects& keys_fruit): board(board_), object_(object), window_(window), keys_fruit_(keys_fruit), game_rules{"resources/sansation.ttf"}
{
    window_.create(sf::VideoMode(1600,900), "SFML Super Pac-Man");
    window_.setFramerateLimit(140);

    x_speed = 0;
    y_speed = 0;

    ghostmovx = 0;
    ghostmovy = 1;
    ghost2movx= 1;
    ghost2movy= 0;
    ghost3movx = -1;
    ghost3movy = 0;
    ghost4movx = -1;
    ghost4movy = 0;

    clock.restart();

    board_.readInBorders();

    if(!buffer.loadFromFile("resources/pacman_chomp.wav"))
        throw -1;
    chomp.setBuffer(buffer);
    chomp.play();
    chomp.setLoop(true);

};

void GamePlay::moveGhost()
{

    if(firstdir)
    {
        ghostmovx = -1;
        ghostmovy =0;
        ghost2movx = 1;
        ghost2movy = 0;
        ghost3movx = -1;
        ghost3movy = 0;
        ghost4movx = 1;
        ghost4movy = 0;
        firstdir = false;
    }

    //Ghost 1: Border Patrol

    if (upwallBlock(board, board.returnBorderPos(), object_.return_border_ghost()))
    {
        object_.GhostSprite.setPosition(object_.GhostSprite.getPosition().x, object_.GhostSprite.getPosition().y+2);
        if (object_.pacman.getPosition().x <= object_.GhostSprite.getPosition().x)
        {
            ghostmovx = -1;
            ghostmovy = 0;
        }
        else
        {
            ghostmovx = 1;
            ghostmovy = 0;
        }
    }

    if (downwallBlock(board, board.returnBorderPos(), object_.return_border_ghost()))
    {
        object_.GhostSprite.setPosition(object_.GhostSprite.getPosition().x, object_.GhostSprite.getPosition().y-2);
        if (object_.pacman.getPosition().x <= object_.GhostSprite.getPosition().x)
        {
            ghostmovx = -1;
            ghostmovy = 0;
        }
        else
        {
            ghostmovx = 1;
            ghostmovy = 0;

        }
    }

    if (rightwallBlock(board, board.returnBorderPos(), object_.return_border_ghost()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost()))
    {
        object_.GhostSprite.setPosition(object_.GhostSprite.getPosition().x+2, object_.GhostSprite.getPosition().y);
        if (object_.pacman.getPosition().y <= object_.GhostSprite.getPosition().y)
        {
            ghostmovx = 0;
            ghostmovy = -1;
        }
        else
        {
            ghostmovx = 0;
            ghostmovy = 1;

        }
    }

    if (leftwallBlock(board, board.returnBorderPos(), object_.return_border_ghost()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost()))
    {
        object_.GhostSprite.setPosition(object_.GhostSprite.getPosition().x-2, object_.GhostSprite.getPosition().y);
        if (object_.pacman.getPosition().y <= object_.GhostSprite.getPosition().y)
        {
            ghostmovx = 0;
            ghostmovy = -1;
        }
        else
        {
            ghostmovx = 0;
            ghostmovy = 1;

        }
    }

    //Ghost 2: Guardian of the Center

    if (rightwallBlock(board, board.returnBorderPos(), object_.return_border_ghost2()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost2()))
    {
        object_.GhostSprite2.setPosition(object_.GhostSprite2.getPosition().x+2, object_.GhostSprite2.getPosition().y);
        ghost2movx = 1;
        ghost2movy = 0;
    }

    if (leftwallBlock(board, board.returnBorderPos(), object_.return_border_ghost2()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost2()))
    {
        object_.GhostSprite2.setPosition(object_.GhostSprite2.getPosition().x-2, object_.GhostSprite2.getPosition().y);
        ghost2movx = -1;
        ghost2movy = 0;
    }

    //Ghost 3: Guardian of the Power Pellets

    if (rightwallBlock(board, board.returnBorderPos(), object_.return_border_ghost3()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost3())&& check1 == false)
    {
        object_.GhostSprite3.setPosition(object_.GhostSprite3.getPosition().x+2, object_.GhostSprite3.getPosition().y);
        ghost3movx = 0;
        ghost3movy = -1;
        check1 = true;
    }
    if (upwallBlock(board, board.returnBorderPos(), object_.return_border_ghost3()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost3())&& check2 == false)
    {
        object_.GhostSprite3.setPosition(object_.GhostSprite3.getPosition().x, object_.GhostSprite3.getPosition().y+2);
        ghost3movx = -1;
        ghost3movy = 0;
        check2 = true;
    }
    if (object_.GhostSprite3.getPosition().x == 330 && check3 == false)
    {
        object_.GhostSprite3.setPosition(object_.GhostSprite3.getPosition().x+2, object_.GhostSprite3.getPosition().y);
        ghost3movx = 0;
        ghost3movy = 1;
        check3 = true;
    }

    if (check3 ==true)
    {
        if (downwallBlock(board, board.returnBorderPos(), object_.return_border_ghost3()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost3()))
        {
            object_.GhostSprite3.setPosition(object_.GhostSprite3.getPosition().x, object_.GhostSprite3.getPosition().y-2);
            ghost3movx = 0;
            ghost3movy = -1;
        }

        if (upwallBlock(board, board.returnBorderPos(), object_.return_border_ghost3()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost3()))
        {
            object_.GhostSprite3.setPosition(object_.GhostSprite3.getPosition().x, object_.GhostSprite3.getPosition().y+2);
            ghost3movx = 0;
            ghost3movy = 1;
        }
    }

    //Ghost 4: The wandering Nomad

    if (rightwallBlock(board, board.returnBorderPos(), object_.return_border_ghost4()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost4()))
    {
        object_.GhostSprite4.setPosition(object_.GhostSprite4.getPosition().x+2, object_.GhostSprite4.getPosition().y);
        randNum = (rand()%4+1);
        if (randNum==1)
        {
            ghost4movx = 1;
            ghost4movy = 0;
        }
        if (randNum==2)
        {
            ghost4movx = -1;
            ghost4movy = 0;
        }
        if (randNum==3)
        {
            ghost4movx = 0;
            ghost4movy = 1;
        }
        if (randNum==4)
        {
            ghost4movx = 0;
            ghost4movy = -1;
        }
    }

    if (leftwallBlock(board, board.returnBorderPos(), object_.return_border_ghost4()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost4()))
    {
        object_.GhostSprite4.setPosition(object_.GhostSprite4.getPosition().x-2, object_.GhostSprite4.getPosition().y);
        randNum = (rand()%4+1);
        if (randNum==1)
        {
            ghost4movx = 1;
            ghost4movy = 0;
        }
        if (randNum==2)
        {
            ghost4movx = -1;
            ghost4movy = 0;
        }
        if (randNum==3)
        {
            ghost4movx = 0;
            ghost4movy = 1;
        }
        if (randNum==4)
        {
            ghost4movx = 0;
            ghost4movy = -1;
        }
    }

    if (upwallBlock(board, board.returnBorderPos(), object_.return_border_ghost4()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost4()))
    {
        object_.GhostSprite4.setPosition(object_.GhostSprite4.getPosition().x, object_.GhostSprite4.getPosition().y+2);
        randNum = (rand()%4+1);
        if (randNum==1)
        {
            ghost4movx = 1;
            ghost4movy = 0;
        }
        if (randNum==2)
        {
            ghost4movx = -1;
            ghost4movy = 0;
        }
        if (randNum==3)
        {
            ghost4movx = 0;
            ghost4movy = 1;
        }
        if (randNum==4)
        {
            ghost4movx = 0;
            ghost4movy = -1;
        }
    }

    if (downwallBlock(board, board.returnBorderPos(), object_.return_border_ghost4()) && !moveThroughOpenWall(storePreviousKeyHits.at(0), board.returnOpenBorderPos(), object_.return_border_ghost4()))
    {
        object_.GhostSprite4.setPosition(object_.GhostSprite4.getPosition().x, object_.GhostSprite4.getPosition().y-2);
        randNum = (rand()%4+1);
        if (randNum==1)
        {
            ghost4movx = 1;
            ghost4movy = 0;
        }
        if (randNum==2)
        {
            ghost4movx = -1;
            ghost4movy = 0;
        }
        if (randNum==3)
        {
            ghost4movx = 0;
            ghost4movy = 1;
        }
        if (randNum==4)
        {
            ghost4movx = 0;
            ghost4movy = -1;
        }
    }
    object_.GhostSprite.move(ghostmovx, ghostmovy);
    object_.GhostSprite2.move(ghost2movx, ghost2movy);
    object_.GhostSprite3.move(ghost3movx, ghost3movy);
    object_.GhostSprite4.move(ghost4movx, ghost4movy);
}

void GamePlay::movePacman( const int& x, const int& y)
{
    x_speed = x;
    y_speed = y;
    object_.pacman.move(x_speed, y_speed);
}


//move pacman
tuple<int, int>GamePlay::KeyPressed(sf::RenderWindow &window, sf::Event event)
{

    switch(event.type)
    {

    case sf::Event::Closed:
        window.close();
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Right  && (!leftwallBlock(board, board.returnBorderPos(), object_.return_border_pac()) || allowEntry))
        {
            y_speed = 0;
            x_speed = 1;
            allowEntry = false;

        }
        else if(event.key.code == sf::Keyboard::Left  && (!rightwallBlock(board, board.returnBorderPos(), object_.return_border_pac()) || allowEntry))
        {
            y_speed = 0;
            x_speed = -1;
            allowEntry = false;

        }
        else if(event.key.code == sf::Keyboard::Up && (!upwallBlock(board, board.returnBorderPos(), object_.return_border_pac()) || allowEntry))
        {
            y_speed = -1;
            x_speed = 0;
            allowEntry = false;
        }
        else if(event.key.code == sf::Keyboard::Down && (!downwallBlock(board, board.returnBorderPos(), object_.return_border_pac()) || allowEntry))
        {
            y_speed = 1;
            x_speed = 0;
            allowEntry = false;
        }
        else if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
        {
            window.close();
        }
    default:
        break;
    }

    return {x_speed, y_speed};
}

void GamePlay::vectorMaths(vector<int> &vec, const int& para)
{
    vec.push_back(para);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

void GamePlay::collision(gameBoard& board, int& currentLives, bool& isPlaying, bool& winner)
{
    auto elapsedTime = clock.getElapsedTime().asSeconds();

//Pac-Man Ghost collision
    if((object_.return_border_pac().intersects(object_.return_border_ghost()) ||object_.return_border_pac().intersects(object_.return_border_ghost2())||object_.return_border_pac().intersects(object_.return_border_ghost3())||object_.return_border_pac().intersects(object_.return_border_ghost4())) && elapsedTime > 8)
    {
        currentLives--;
        object_.updatePacman();
    }

//Fruit and Key collisions
    auto [c, d] = FruitCollision1(object_,board.return_RectfruitObj());
    auto [a, b] = KeyCollision(object_, board.return_RectkeyObj());

    vectorMaths(storePreviousKeyHits, a);

    if(b == true)
    {
        cout << a << endl;
        board.KEYS.at(a) = nullptr;
        currentScore+=10;
        board.updateGameBoard(a);
    }

    for(auto i = 0; i < storePreviousKeyHits.size(); i++) //should implement in base movement class
    {
        if(moveThroughOpenWall(storePreviousKeyHits.at(i), board.returnOpenBorderPos(), object_.return_border_pac()))
        {
            allowEntry = true;
            return;
        }
    }

    vectorMaths(storePreviousFruitHits, c);

    if(d == true)
    {
        board.FRUIT.at(c) = nullptr;
        currentScore+=10;
        fruiteaten++;
    }

    //Win game check
    if(fruiteaten==76)
    {
        isPlaying = false;
        winner = true;
    }

    //Pac-Man Power Pellet collision
    if(PacEatsPowerPellet(object_))
    {
        clock.restart();
    }

    if(elapsedTime < 8 && PacEatsPowerPellet(object_))
    {
        currentScore = currentScore + 50;
        updateGameforPowerPellet(object_);
        chomp.setLoop(false);
    }

    else if(elapsedTime > 8)
    {
        normalConditions(object_);
    }

    //Pac-Man wall collision
    if(leftwallBlock(board, board.returnBorderPos(),object_.return_border_pac())) //can add in ghost movement here to check simultaneously
    {
        x_speed = 0;

    }
    if(rightwallBlock(board, board.returnBorderPos(), object_.return_border_pac()))
    {
        x_speed = 0;
    }
    if(downwallBlock(board, board.returnBorderPos(), object_.return_border_pac()))
    {
        y_speed = 0;
    }
    if(upwallBlock(board, board.returnBorderPos(), object_.return_border_pac()))
    {
        y_speed = 0;
    }
}

void GamePlay::drawAllObjects()
{
    object_.drawSprites(window_);
    board.drawBorders();                //keys and fruit included here

}


void GamePlay::gameLoop()
{
    bool isPlaying = false;
    bool FruitEaten = false;

    while (window_.isOpen())
    {

        sf::Event event;
        while (window_.pollEvent(event))
        {
            // Press space to begin the game
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {

                isPlaying = true;

            }
            drawStartMessage(window_);
        }
        window_.clear();

        if(isPlaying==true && currentLives > 0)
        {
            auto [x, y] = KeyPressed(window_, event);
            movePacman(x, y);
            moveGhost();
            drawAllObjects();
            collision(board, currentLives, isPlaying, winner);
            drawScoreMessage(currentScore, window_);
            drawLivesMessage(currentLives, window_);
        }
        else if (winner == true)
        {
            drawWinMessage(window_);
            drawStartMessage(window_);
        }
        else
        {
            drawLoseMessage(currentLives, window_);
            drawStartMessage(window_);
            KeyPressed(window_, event);
        }
        window_.display();
    }
}
