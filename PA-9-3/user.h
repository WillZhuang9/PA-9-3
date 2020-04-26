//
//  user.hpp
//  PA-9-3
//
//  Created by will on 4/25/20.
//  Copyright © 2020 will. All rights reserved.
//

#ifndef user_hpp
#define user_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"
#include "GameEngine.h"
class user: public player, public Map
{
protected:
    int move;
public: 
    user(sf::Color color, Map map, int pos):player(color, map, pos)
    {
        move =0;
    }
    int checkwin();
    int checktie(int);
    
};
#endif /* user_hpp */
