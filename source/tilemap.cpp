#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../include/tilemap.h"
#include <cmath>

using namespace sf;
using namespace std;


TileMap::TileMap()
{
    // create tile map
    this->map = new int*[6];
    for(int i = 0; i < 6; i++)
    {
        this->map[i] = new int[10];
    }

    //create tile on the map
    //add tiles into tile vector
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            this->map[i][j] = rand() % 2; // 1 - tiles exist, 0 - tiles don't exist
            if(map[i][j] == 1)
            {
                //add a tile into vector
                this->tileList.push_back(new Tile(40 + i*87, j * 30));
            }
        }
    }
}

vector<Tile*>& TileMap::getTileList()
{
    return this->tileList;
}

void TileMap::update(RenderWindow& window)
{
    for(int i = 0; i < this->tileList.size(); i++)
    {
        this->tileList[i]->update(window);
    }
}
void TileMap::deleteTile(int idx)
{
    //free memory
    delete this->tileList[idx];

    //remove tile from the vector
    this->tileList.erase(this->tileList.begin() + idx);
}

