//
//  Menu.cpp
//  PA-9-3
//
//  Created by will on 4/27/20.
//  Copyright © 2020 will. All rights reserved.
//


#include "Menu.h"
#include <cstdlib>

void MainMenu::instructions(void)
{
      sf::RenderWindow window(sf::VideoMode(400, 400), "Instructions");
            
             sf::Font font;
             font.loadFromFile("sansation.ttf");
                    
             sf::Text text1 ("How to play Checkers!", font);
             text1.setCharacterSize(40);
             text1.setFillColor(sf::Color::Red);
             text1.setPosition(10, 20);
        
             sf::Text text2 ("Two players have to play, one is red and one is blue", font);
             text2.setCharacterSize(15);
             text2.setFillColor(sf::Color::Yellow);
             text2.setPosition(10, 70);

             sf::Text text3 ("You can only move diagonally", font);
             text3.setCharacterSize(15);
             text3.setFillColor(sf::Color::Yellow);
             text3.setPosition(10, 120);
        
             sf::Text text4 ("If you jump over the opponents piece, they lose the piece", font);
             text4.setCharacterSize(15);
             text4.setFillColor(sf::Color::Yellow);
             text4.setPosition(10, 170);
    
             sf::Text text5 ("You win by killing all the opponents pieces", font);
             text5.setCharacterSize(15);
             text5.setFillColor(sf::Color::Yellow);
             text5.setPosition(10, 230);
        
             sf::Text text6 ("You win by killing all the opponents pieces", font);
             text6.setCharacterSize(15);
             text6.setFillColor(sf::Color::Yellow);
             text6.setPosition(10, 280);
    
             sf::Text text7 ("Press '3' to return back to main menu!", font);
             text7.setCharacterSize(15);
             text7.setFillColor(sf::Color::Blue);
             text7.setPosition(10, 330);
    
    
        
             // run the program as long as the window is open
             while (window.isOpen())
             {
                 // check all the window's events that were triggered since the last iteration of the loop
                 // check the type of the event...
                 sf::Event event;
                 
                while (window.pollEvent(event))
                 {
                     // check the type of the event...
                     switch (event.type)
                     {
                         // window closed
                         case sf::Event::Closed:
                             window.close();
                             break;
                             
                         case sf::Event::KeyPressed:
                             if(event.key.code == sf::Keyboard::Num3){
                                 window.close();
                             }
                                 
                             break;
                        
                         default:
                             break;
                     }
                 }
                 // clear the window with black color
                 window.clear(sf::Color::Black);
                 
                 window.draw(text1);
                 window.draw(text2);
                 window.draw(text3);
                 window.draw(text4);
                 window.draw(text5);
                 window.draw(text6);
                 window.draw(text7);
                 
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        cout << "It worked";
                        window.close();
                    }
                 
                 // end the current frame
                 window.display();
             }
        return 0;
}

int MainMenu::main(void)
{
       // create the window
        
         char choice;
    
         sf::RenderWindow window(sf::VideoMode(400, 400), "Menu");
        
         sf::Font font;
         font.loadFromFile("sansation.ttf");
                
         sf::Text text1 ("Main Menu", font);
         text1.setCharacterSize(40);
         text1.setFillColor(sf::Color::Red);
         text1.setPosition(20, 20);
    
         sf::Text text2 ("1) play", font);
         text2.setCharacterSize(20);
         text2.setFillColor(sf::Color::Yellow);
         text2.setPosition(20, 120);

         sf::Text text3 ("2) instructions", font);
         text3.setCharacterSize(20);
         text3.setFillColor(sf::Color::Yellow);
         text3.setPosition(20, 220);
    
         sf::Text text4 ("3) exit", font);
         text4.setCharacterSize(20);
         text4.setFillColor(sf::Color::Yellow);
         text4.setPosition(20, 320);
    
    
         // run the program as long as the window is open
         while (window.isOpen())
         {
             // check all the window's events that were triggered since the last iteration of the loop
             // check the type of the event...
             sf::Event event;
             
            while (window.pollEvent(event))
             {
                 // check the type of the event...
                 switch (event.type)
                 {
                     // window closed
                     case sf::Event::Closed:
                         window.close();
                         break;

                     // key pressed
                     case sf::Event::KeyPressed:
                         if (event.key.code == sf::Keyboard::Num1)
                         {
                             window.close();
                         }
                         
                         if (event.key.code == sf::Keyboard::Num2)
                         {
                             instructions();
                         }
                         
                         if (event.key.code == sf::Keyboard::Num3)
                         {
                             return 1;                         }
                         
                         break;

                     // we don't process other types of events
                     default:
                         break;
                 }
             }
             // clear the window with black color
             window.clear(sf::Color::Black);
             
             window.draw(text1);
             window.draw(text2);
             window.draw(text3);
             window.draw(text4);
             
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    cout << "It worked";
                    window.close();
                }
             
             // end the current frame
             window.display();
         }
    return 0;
}
