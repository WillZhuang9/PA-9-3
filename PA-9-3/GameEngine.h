
#ifndef GameEngine_h
#define GameEngine_h

#include<SFML/Graphics.hpp>

sf::RectangleShape setStandardItem(sf::Vector2f, sf::Color);
bool checkCollision(const sf::RectangleShape&, const sf:: RectangleShape&);
void showUIinGame(sf::RenderWindow*);

#endif /* GameEngine_hpp */
