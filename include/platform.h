#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

class Platform
{
private:
     Image platformImage;
     Texture platformTexture;
     Sprite platformSprite;

public:

    /**
    * default constructor
    */
    Platform();


    /**
    * getter function
    * get copy sprite platform
    * a copy can be used by other classes
    * copy have the size and the position
    * original sprite
    * @return a copy of sprite ball
    */
    Sprite getPlatformSprite();


    /**
    * update function
    * it is used to process and display the platform
    * @param main window
    * @param game time
    */
    void update(RenderWindow&, float);

private:
    /**
    * function that checks the collision
    * of the platform with the walls
    * @return 1 - if the platform is located in the right corner of the screen
    * ////// -1 - if the platform is located in the left corner of the screen
    * //////  0 - if the platform is not located in one of corners of the screen
    */
    int collision();


    /**
    * move the platform to the right side
    * @param game speed
    */
    void moveRight(float);


    /**
    * move the platform to the left side
    * @param game speed
    */
    void moveLeft(float);


    /**
    * general movement depending on the keystroke event
    * and location platform
    * @param game speed
    */
    void move(float);

};
#endif // PLATFORM_H_INCLUDED
