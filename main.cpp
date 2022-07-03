#include "mapTile.h"
#include <random>
using engine = std::mt19937;

engine rng;
std::vector<std::vector<mapTile>> Tiles;

void initialize(int size[2])
{
    //setting size of the map, and initializing the tiles of the map.
    Tiles.resize(size[0]);
    rng.seed(5);
    std::normal_distribution<double> normal_dist(1000, 200);

    for(int i = 0; i < size[0]; i++)
    {
        Tiles[i].resize(size[1]);
        
        for(int j = 0; j < size[1]; j++)
        {
            double x[5] = {normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng)};
            Tiles[i][j].resources = x;
        }
    }
}



int main()
{
    initialize(MAP_DIM); 
    /*Will set up the relevant classes etc., to be executed once:
    This might be present as a separate CPP file at the end, using this project
    as the Update() function instead*/
    // Update() : Assuming the input is a file with instructions for 
    // change line-wise, this will make those changes one-by one.
    // A lot is left to be figured, but then this is testing git.
}