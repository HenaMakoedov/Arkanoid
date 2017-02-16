#include <SFML/Graphics.hpp>
#include "../include/platform.h"


using namespace sf;
extern const String SPRITES;

    Platform::Platform()
    {
        //set the default setting for platform
        this->platformImage.loadFromFile(SPRITES);
        this->platformTexture.loadFromImage(platformImage);

        this->platformSprite.setTexture(platformTexture);
        this->platformSprite.setTextureRect(IntRect(0.0,200.0,96.0,28.0));
        this->platformSprite.setPosition(252.0,550.0);
    }


    Sprite Platform::getPlatformSprite()
    {
         return this->platformSprite;
    }

    void Platform::moveRight(float time)
    {
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            //move the platform sprite to the right
            this->platformSprite.move( 0.1 * time, 0);
        }
    }

    void Platform::moveLeft(float time)
    {
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            //move the platform sprite to the left
            this->platformSprite.move(-0.1 * time, 0);
        }
    }


    void Platform::move(float time)
    {
        if (this->collision() == 0)
        {
            this->moveRight(time);
            this->moveLeft(time);
        }

        if (this->collision() == 1)
        {
            this->moveLeft(time);
        }

        if (this->collision() == -1)
        {
            this->moveRight(time);
        }
    }

    int Platform::collision()
    {
        //get the coordinate x and width of platform
        float x = this->platformSprite.getPosition().x;
        float width = this->getPlatformSprite().getTextureRect().width;

        // if the platform is located in the right corner of the screen
        if (x + width >= 596.0) {return 1;}

        // if the platform is located in the left corner of the screen
        if (x <= 4.0) {return -1;}

        //if the platform is not located in one of corners of the screen
        else {return 0;}
    }

    void Platform::update(RenderWindow& window, float time)
    {
        //move the platform
        this->move(time);

        //draw the platform on the screen
        window.draw(this->getPlatformSprite());
    }
