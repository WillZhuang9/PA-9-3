//
//  map.hpp
//  PA-9-3
//
//  Created by will on 4/25/20.
//  Copyright © 2020 will. All rights reserved.
//
#ifndef map_h
#define map_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
using namespace std;
class Map
{
protected:
    struct border
    {
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    struct mouse
    {
        sf::Vector2f location;
        sf::RectangleShape item;
    };
    struct border map[8][8];
    struct mouse obj;
public:
    Map();
    void moveobj(int);
    sf::RectangleShape getLocalposition()
    {
        return obj.item;
    }
    
    sf::RectangleShape getMap(int n, int m)
    {
        return map[n][m].item;
    }
};

#endif /* map_h */
