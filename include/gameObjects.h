#ifndef GAMEOBJECTS_H_INCLUDED
#define GAMEOBJECTS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "platform.h"
#include "tilemap.h"
#include "backGround.h"

using namespace sf;


class GameObjects
{
private:

    //pointer to the game objects
    Ball* ptrBall;
    Platform* ptrPlatform;
    BackGround* ptrBackGround;
    TileMap* ptrTileMap;

    //tiles vector
    vector<Tile*> tileList;

public:

    /**
    * Parametrized Constructor
    * @param pointer to the ball
    * @param pointer to the platform
    * @param pointer to the background
    * @param pointer to the tile map
    */
    GameObjects(Ball*, Platform*, BackGround*, TileMap*);


    /**
    * update function
    * it is used to process and display the game objects
    * @param main window
    * @param game time
    */
    void update(RenderWindow&, float);

private:

    /**
    * function that checks the collision
    * of the ball with the platform
    * and changes the direction of the ball
    */
    void ballCollisionWithPlatform();


    /**
    * function that checks the collision
    * of the ball with the walls
    * and changes the direction of the ball
    */
    void ballCollisionWithWalls();


    /**
    * function that checks the collision
    * of the ball with the tiles
    * and changes the direction of the ball
    */
    void ballcollisionWithTiles();


    /**
    * general of the ball collision with the game objects
    */
    void ballCollision();

    /**
    * the condition of losing the game
    */
    bool isLose();


    /**
    * game win condition
    */
    bool isWin();
};

#endif // GAMEOBJECTS_H_INCLUDED
