
//
//  user.cpp
//  PA-9-3
//
//  Created by will on 4/25/20.
//  Copyright © 2020 will. All rights reserved.
//

#include "user.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int user:: checkwin()
{
  if(num == 0)
      return 1;
    return 0;
}
int user::checktie(int a)
{
    if(a == 1)
        move = 0;
    else
        move += 1;
    if (move == 100)
        return 1;
    return 0;
}
