#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.h"

using namespace sf;
using namespace std;

class TileMap
{
private:
    // map tiles
    int** map;

    // vector tiles
    vector<Tile*> tileList;
    
public:
    /**
    * Default Constructor
    * set the default setting for the tile map
    */
    TileMap();


    /**
    * getter function
    * @return a reference to the vector tiles
    */
    vector<Tile*>& getTileList();

    /**
    * update function
    * it is used to display the tile map
    * @param main window
    */
    void update(RenderWindow&);


    /**
    * remove tile from the tile vector
    */
    void deleteTile(int);
};
#endif // TILEMAP_H_INCLUDED
