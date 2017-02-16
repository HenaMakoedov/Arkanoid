#include <SFML/Graphics.hpp>
#include "../include/backGround.h"

using namespace sf;
extern const String BACKGROUND;


BackGround::BackGround()
{
    //set default setting for background
   this->backGroundImage.loadFromFile(BACKGROUND);
   this->backGroundTexture.loadFromImage(this->backGroundImage);

   this->backGroundSprite.setTexture(this->backGroundTexture);
   this->backGroundSprite.setPosition(0,0);

}

Sprite BackGround::getBackGroundSprite()
{
    return this->backGroundSprite;
}

void BackGround::update(RenderWindow& window)
{
    //draw background on the screen
    window.draw(this->getBackGroundSprite());
}
