#pragma once
#include <SFML/Graphics.hpp> // Can we include just the rectangle shape?
#include "Common.h"

class Bird : public sf::RectangleShape
{
   const float JUMP_SPEED = -0.3f;
   float Velocity;

public:
   Bird(sf::Vector2f size) : RectangleShape(size)
   {
      setFillColor(sf::Color::White);
      Velocity = 0;
      setPosition(50, 50);
   }

   ///////////////////////////
   // Actions

   void jump()
   {
      Velocity = JUMP_SPEED;
   }

   void stop()
   {
      Velocity = 0;
   }

   void gravity()
   {
      Velocity += GRAVITY;
   }

   ////////////////////////////
   // Velocity utils

   float getVelocity()
   {
      return Velocity;
   }

   void setVelocity(float VelocityUse)
   {
      Velocity = VelocityUse;
   }

   void changeVelocityBy(float delta)
   {
      Velocity += delta;
   }

   ///////////////////////////
   // Boundary checks

   bool IsOut_Top()
   {
      return getPosition().y <= 0;
   }

   bool IsOut_Bottom(int ScreenHeight)
   {
      return getPosition().y >= ScreenHeight - getSize().y;
   }
};