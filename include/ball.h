#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "platform.h"
#include "tilemap.h"

using namespace sf;

class Ball
{
private:

    float dx; // speed along the x coordinate
    float dy; // speed along the y coordinate
    Image ballImage;
    Texture ballTexture;
    Sprite ballSprite;
public:

    /**
    * Default Constructor
    * set the default setting for the ball
    */
    Ball();

    /**
    * getter function
    * get copy sprite ball
    * a copy can be used by other classes
    * copy have the size and the position
    * original sprite
    * @return a copy of sprite ball
    */
    Sprite getBallSprite();


    /**
    * getters and setters speed along coordinates
    */
    float getDx();
    float getDy();
    void setDx(float);
    void setDy(float);


    /**
    * update function
    * it is used to process and display the ball
    * @param main window
    * @param game time
    */
    void update(RenderWindow&,float);

private:

    /** function which is responsible for the movement of the ball
    * @param game speed
    */
    void move(float);
};
#endif // BALL_H_INCLUDED
