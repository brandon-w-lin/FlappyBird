#pragma once

//#include <iostream>
#include <SFML/Graphics.hpp>
//#include <cmath>
#include "Bird.h"
#include "Game.h"

void Game::PlayGame()
{
      sf::RenderWindow window(sf::VideoMode(500, 500), "crappy bird", sf::Style::Close | sf::Style::Resize);
      
      Bird bird(sf::Vector2f(50,50));
   
      while (window.isOpen())
      {
         sf::Event event;
         while (window.pollEvent(event))
         {
            switch (event.type)
            {
            case (sf::Event::Closed): 
               window.close();
               break;
            case (sf::Event::Resized):
               break;
            case (sf::Event::TextEntered):
               printf("%c", event.text.unicode);
               break;
            }
   
         }
   
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
         {
            bird.jump();
         }      
        
         if (bird.IsOut_Top())
         {
            bird.setVelocity(0);
            bird.gravity();
         }
         else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bird.IsOut_Bottom(window.getSize().y))
         {
            bird.setVelocity(0);
         }
         else
         {
            bird.gravity();
         }
         
   
         bird.move(0.0f, bird.getVelocity());
   
         window.clear();
         window.draw(bird);
         window.display();
      }

};


