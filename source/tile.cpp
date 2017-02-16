#include <SFML/Graphics.hpp>
#include "../include/tile.h"
using namespace sf;

extern const String SPRITES;

Tile::Tile(float x, float y)
{
    //set default setting of the tile
    this->tileImage.loadFromFile(SPRITES);
    this->tileTexture.loadFromImage(this->tileImage);

    this->tileSprite.setTexture(this->tileTexture);
    this->tileSprite.setTextureRect(IntRect(280.0,180.0,87.0,30.0));
    this->tileSprite.setPosition(x,y);
}

Sprite Tile::getSprite()
{
    return this->tileSprite;
}

void Tile::update(RenderWindow& window)
{
    window.draw(this->getSprite());

}

