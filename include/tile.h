#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile
{
private:
    Image tileImage;
    Texture tileTexture;
    Sprite tileSprite;

public:
    /**
    * Parametrized Constructor
    * @param x coordinate of the tile
    * @param y coordinate of the tile
    */
    Tile(float, float);


    /**
    * getter function
    * @return a copy of sprite tile
    */
    Sprite getSprite();


    /**
    * update function
    * it is used to display the tile
    * @param main window
    */
    void update(RenderWindow&);
};

#endif // TILE_H_INCLUDED
