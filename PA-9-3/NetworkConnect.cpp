//
//  NetworkConnect.cpp
//  PA-9-3
//
//  Created by will on 4/27/20.
//  Copyright © 2020 will. All rights reserved.
//

#include "NetworkConnect.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include<string>
#include <iostream>
#include <sstream>

int EnterScreen()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Instructions");
     window.setFramerateLimit(30);
    
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    
    sf::Text text1 ("Player or Server\n(1) Player, (2) Server", font);
    text1.setCharacterSize(40);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(10, 20);
    
    sf::Text text2 ("", font);
      text2.setCharacterSize(40);
      text2.setFillColor(sf::Color::Red);
      text2.setPosition(40, 100);
    int get = 0;
    
    
    sf::TcpSocket socket;
    std::string consoleInpute = "192.168.1.4";
    
    sf::TcpListener listener;
    listener.listen(55001);
    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        // check the type of the event...
        
        sf::Event event;
        while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        }
      
        if (event.key.code == sf::Keyboard::Num1)
        {
            get = 1;
        }
        if(get == 1) // client-side
        {
            
            socket.connect(consoleInpute, 55001);
                
            //Sned a message to the connected host
            std::string message = "Hi, I am a client from PA-9";
            socket.send(message.c_str(), message.size() + 1);
                    
            //Receive an asnwer from the server
            char buffer[1024];
            std::size_t received = 0;
            socket.receive(buffer, sizeof(buffer), received);
            std::string s;
            std::stringstream ss;
            ss << buffer;
            ss >> s;
            text1.setString(s);
            get = 1;
        }
                    
        if (event.key.code == sf::Keyboard::Num2)
        {
            get = 2;
            
        }
        if (get == 2) // server-side
        {
            
           // sf::TcpSocket socket;
            listener.accept(socket);
            std::string n = "New client connected: ";
            n += socket.getRemotePort();
        
            char buffer[1024];
            std::size_t received = 0;
            socket.receive(buffer, sizeof(buffer), received);
            std::string s(buffer);
//            std::stringstream ss;
//
//            int a_size = sizeof(buffer)/sizeof(char);
//
//            s = convert
            
            
//            ss << buffer;
//            ss >> s;
            text2.setString(s);
            window.draw(text2);
        
            std::string message = "Welcome, client";
            socket.send(message.c_str(), message.size() + 1);
        }
        window.draw(text1);
        window.display();
    }
    window.close();
    return 1;
}
void GetmainScreen()
{
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        EnterScreen();
    }
}
