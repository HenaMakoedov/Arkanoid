#include "../include/gameObjects.h"
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;


GameObjects::GameObjects(Ball* ptrBall, Platform* ptrPlatform,
                         BackGround* ptrBackGround, TileMap* ptrTileMap)
{
    // initialize the fields
    this->ptrBall = ptrBall;
    this->ptrPlatform = ptrPlatform;
    this->ptrTileMap = ptrTileMap;
    this->ptrBackGround = ptrBackGround;
    this->tileList = ptrTileMap->getTileList();
}

void GameObjects::ballCollisionWithPlatform()
{
    //get the coordinates and dimensions
    //of the ball sprite and platform sprite
    Vector2f ballCoordinates = this->ptrBall->getBallSprite().getPosition();
    IntRect ballRect = this->ptrBall->getBallSprite().getTextureRect();
    Vector2f platformCoordinates = ptrPlatform->getPlatformSprite().getPosition();
    IntRect platformRect = ptrPlatform->getPlatformSprite().getTextureRect();

     //if the ball collides with the platform
    if(ballCoordinates.y + ballRect.height >= platformCoordinates.y &&
       ballCoordinates.y <= platformCoordinates.y + platformRect.height &&
       ballCoordinates.x + ballRect.width >= platformCoordinates.x &&
       ballCoordinates.x <= platformCoordinates.x + platformRect.width)
    {

        //if the ball collides with platform edges
       if((ballCoordinates.x + ballRect.width <= platformCoordinates.x + platformRect.width / 8 &&
           this->ptrBall->getDx() > 0) ||
          (ballCoordinates.x >= platformCoordinates.x + (platformRect.width / 8) * 7 &&
           this->ptrBall->getDx() < 0))
       {
           //change direction
           this->ptrBall->setDx(-(this->ptrBall->getDx()));
           this->ptrBall->setDy(-(this->ptrBall->getDy()));
       }

        //if the ball collides with platform center
       else
       {
           //change direction
           float d =(float)(rand() % 3) / 10 + 0.9;
           this->ptrBall->setDx(this->ptrBall->getDx() * d);
           this->ptrBall->setDy(this->ptrBall->getDy() / (-d));
       }
    }
}

void GameObjects::ballCollisionWithWalls()
{
     //get the coordinates and size of the ball sprite
    Vector2f ballCoordinates = this->ptrBall->getBallSprite().getPosition();
    IntRect ballRect = this->ptrBall->getBallSprite().getTextureRect();

    //if the ball collides with the walls
    if(ballCoordinates.x < 2 || ballCoordinates.x + ballRect.width > 592)
    {
        this->ptrBall->setDx(-(this->ptrBall->getDx()));
    }
    else if(ballCoordinates.y < 2)
    {
        this->ptrBall->setDy(-(this->ptrBall->getDy()));
    }
}

void GameObjects::ballcollisionWithTiles()
{
    //get the coordinates and size of the ball sprite
    Vector2f ballCoordinates = this->ptrBall->getBallSprite().getPosition();
    IntRect ballRect = this->ptrBall->getBallSprite().getTextureRect();

    //get the coordinates of the center ball sprite
    Vector2f ballCentre;
    ballCentre.x = ballCoordinates.x + ballRect.width / 2;
    ballCentre.y = ballCoordinates.y + ballRect.height / 2;


    for(int i = 0; i < this->tileList.size(); i++)
    {
        //get the tile coordinates
        Vector2f tileCoordinates = this->tileList[i]->getSprite().getPosition();
        IntRect tileRect = this->tileList[i]->getSprite().getTextureRect();

        //if the ball collides with the any tile
        if(ballCoordinates.x + ballRect.width >= tileCoordinates.x &&
           ballCoordinates.x <= tileCoordinates.x + tileRect.width &&
           ballCoordinates.y + ballRect.height >= tileCoordinates.y &&
           ballCoordinates.y <= tileCoordinates.y + tileRect.height)
        {
            //if the ball collides with right part of tile
           if(ballCoordinates.x + ballRect.width >= tileCoordinates.x &&
              ballCentre.x < tileCoordinates.x)
           {
               this->ptrBall->setDx(-(this->ptrBall->getDx()));
           }

            //if the ball collides with left part of tile
           else if(ballCoordinates.x <= tileCoordinates.x + tileRect.width &&
              ballCentre.x > tileCoordinates.x + tileRect.width)
           {
               this->ptrBall->setDx(-(this->ptrBall->getDx()));
           }

            //if the ball collides with top of tile
           else if (ballCoordinates.y + ballRect.height >= tileCoordinates.y &&
               ballCentre.y < tileCoordinates.y)
           {
               this->ptrBall->setDy(-(this->ptrBall->getDy()));
           }

           //if the ball collides with bottom of tile
           else if (ballCoordinates.y <= tileCoordinates.y + tileRect.height &&
               ballCentre.y > tileCoordinates.y + tileRect.height)
           {
               this->ptrBall->setDy(-(this->ptrBall->getDy()));
           }

           //remove tile from the vector
           this->tileList.erase(tileList.begin() + i);

           //free memory
           this->ptrTileMap->deleteTile(i);

        }
    }
}

void GameObjects::ballCollision()
{
    this->ballCollisionWithPlatform();
    this->ballcollisionWithTiles();
    this->ballCollisionWithWalls();
}

bool GameObjects::isLose()
{
    //if the ball is below the platform
    if (this->ptrBall->getBallSprite().getPosition().y >= 600)
    {
        return true;
    }
    return false;
}

bool GameObjects::isWin()
{
    //if no more tiles
    if(this->tileList.size() <= 0)
    {
        return true;
    }
    return false;
}

void GameObjects::update(RenderWindow& window, float time)
{
    if(this->isWin() || this->isLose())
    {
        window.close();
    }

    //logic and rendering of game objects
    this->ballCollision();
    this->ptrBackGround->update(window);
    this->ptrBall->update(window, time);
    this->ptrPlatform->update(window, time);
    this->ptrTileMap->update(window);
}


