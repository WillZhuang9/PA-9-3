
#ifndef player_h
#define player_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;
#include "GameEngine.h"
#include "map.h"

class player
{
protected:
    struct chess
    {
        sf::Color color;
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    int num = 12;
    chess checker[3][4];
public:
    player(sf::Color, Map, int);
    sf::RectangleShape getChecker(int n, int m)
    {
        return checker[n][m].item;
    }
    
    virtual int checkwin() = 0;     // polymorphic - pure virtual function
    virtual void checktie(int) = 0; // polymorphic - pure virtual function
    virtual int get_tie() = 0;      // polymorphic - pure virtual function
    
    int moveObj(sf::Vector2f, sf::Vector2f, int, sf::RectangleShape);
    bool Getposition(sf::Vector2f);
    void moveToTrash(sf::Vector2f);
    int returnnum()
    {
        return num;
    }
    void setnum()
    {
        num = 0;
    }
    
};

#endif /* player_hpp */

