#include "GameRules.h"

game_rules::game_rules(string myfont)
{
    if(!font1.loadFromFile(myfont))
    {
        cout<<"error loading font";
    }
    LivesMessage_.setFont(font1);
    LivesMessage_.setCharacterSize(20);
    LivesMessage_.setPosition(1500, 10);
    LivesMessage_.setFillColor(sf::Color::White);
    LivesMessage_.setString("LIVES: 3");

    StartMessage.setFont(font1);
    StartMessage.setCharacterSize(50);
    StartMessage.setPosition(100, 200);
    StartMessage.setFillColor(sf::Color::White);
    StartMessage.setString("Welcome to SFML Super Pac-Man!\n\nUse the Keyboard Up, Down, Right and Left to move\n\nPress Esc to exit the game\n\nPress space to start the game");

    LoseMessage.setFont(font1);
    LoseMessage.setCharacterSize(50);
    LoseMessage.setPosition(100, 100);
    LoseMessage.setFillColor(sf::Color::White);

    ScoreMessage.setFont(font1);
    ScoreMessage.setCharacterSize(20);
    ScoreMessage.setPosition(10, 10);
    ScoreMessage.setFillColor(sf::Color::White);
    ScoreMessage.setString("SCORE: 0");

    WinMessage.setFont(font1);
    WinMessage.setCharacterSize(50);
    WinMessage.setPosition(100, 100);
    WinMessage.setFillColor(sf::Color::White);
    WinMessage.setString("YOU WIN!!!!!");

    local_class_check = 0;
    clock.restart();
}


tuple<int, bool> game_rules::FruitCollision1(sprites& pac, const vector<sf::FloatRect> &FRUIT) const
{

    for(auto i = 0; i < FRUIT.size(); i++)
    {
        if(pac.return_border_pac().intersects(FRUIT.at(i)))
        {
            return {i, true};
        }
    }
    return {0, false};
}

tuple<int, bool> game_rules::KeyCollision(sprites& pac, const vector<sf::FloatRect> &KEYS) const
{
    for(auto i = 0; i < KEYS.size(); i++)
    {
        if(pac.return_border_pac().intersects(KEYS.at(i)))
        {
            return {i, true};
        }
    }
    return {0, false};

}

void game_rules::normalConditions(sprites& spr)
{
    spr.GhostSprite.setColor(sf::Color::Blue);
    spr.GhostSprite2.setColor(sf::Color::Blue);
    spr.GhostSprite3.setColor(sf::Color::Blue);
    spr.GhostSprite4.setColor(sf::Color::Blue);
}

void game_rules::updateGameforPowerPellet(sprites& spr)
{

    spr.updatePowerPellet(local_class_check);

    if(spr.return_border_pac().intersects(spr.return_border_ghost()))
    {
        spr.GhostSprite.setPosition(780, 400);
    }
    if(spr.return_border_pac().intersects(spr.return_border_ghost2()))
    {
        spr.GhostSprite2.setPosition(780, 400);
    }
    if(spr.return_border_pac().intersects(spr.return_border_ghost3()))
    {
        spr.GhostSprite3.setPosition(780, 400);
    }
    if(spr.return_border_pac().intersects(spr.return_border_ghost4()))
    {
        spr.GhostSprite4.setPosition(780, 400);
    }
}

bool game_rules::PacEatsPowerPellet(sprites& pac)
{
    for(auto i = 0; i < pac.return_border_powerPellet().size(); i++)
    {
        if(pac.return_border_pac().intersects(pac.return_border_powerPellet().at(i)))
        {
            local_class_check = i;
            return true;
        }
        return false;
    }
}

void game_rules::drawScoreMessage( int& currentscore, sf::RenderWindow &window)
{
    std::stringstream ss;
    ss<<"SCORE: "<<currentscore;
    ScoreMessage.setString(ss.str());
    window.draw(ScoreMessage);
}

void game_rules::drawStartMessage(sf::RenderWindow &window)
{
    window.draw(StartMessage);
}

void game_rules::drawWinMessage(sf::RenderWindow &window)
{
    window.draw(WinMessage);
}

void game_rules::drawLoseMessage(int& currentLives, sf::RenderWindow &window)
{
    std::stringstream ss1;
    ss1<<"LIVES REMAINING: "<<currentLives;
    LoseMessage.setString(ss1.str());
    LoseMessage.setPosition(100, 700);
    LoseMessage.setCharacterSize(120);
    LoseMessage.setColor(sf::Color::Red);
    window.draw(LoseMessage);
}

void game_rules::drawLivesMessage(int& currentLives, sf::RenderWindow &window)
{
    std::stringstream ss1;
    ss1<<"LIVES: "<<currentLives;
    LivesMessage_.setString(ss1.str());
    window.draw(LivesMessage_);
}
