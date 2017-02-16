#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;


class BackGround
{
private:
    Image backGroundImage;
    Texture backGroundTexture;
    Sprite backGroundSprite;

public:

    /**
    * default constructor
    */
    BackGround();


    /**
    * getter function
    * get copy sprite background
    * a copy can be used by other classes
    * copy have the size and the position
    * original sprite
    * @return a copy of sprite background
    */
    Sprite getBackGroundSprite();


    /**
    * update function
    * it is used to display the background
    * @param main window
    */
    void update(RenderWindow&);
};
#endif // BACKGROUND_H_INCLUDED
