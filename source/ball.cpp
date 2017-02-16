#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "../include/ball.h"

using namespace std;
using namespace sf;
extern const String SPRITES;

Ball::Ball()
{
    //set the default setting for ball
    this->ballImage.loadFromFile(SPRITES);
    this->ballTexture.loadFromImage(this->ballImage);

    this->ballSprite.setTexture(this->ballTexture);
    this->ballSprite.setTextureRect(IntRect(159.0,199.0,16.0,16.0));
    this->ballSprite.setPosition(300.0,500.0);

    //set the initial speed
    this->dx = 0.05;
    this->dy = -0.05;

}

void Ball::move(float time)
{
    //move the ball sprite
    this->ballSprite.move(this->dx * time,this->dy * time);
}

Sprite Ball::getBallSprite()
{
    return this->ballSprite;
}

float Ball::getDx()
{
    return this->dx;
}

float Ball::getDy()
{
    return this->dy;
}

void Ball::setDx(float dx)
{
    this->dx = dx;
}

void Ball::setDy(float dy)
{
    this->dy = dy;
}

void Ball::update(RenderWindow& window, float time)
{
    //move the ball sprite
    this->move(time);

    //draw ball on the screen
    window.draw(this->getBallSprite());
}


