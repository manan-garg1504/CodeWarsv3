#include "team.h"

//The random parts are to make resource values
#include <random>
using engine = std::mt19937;

engine rng;

void initialize(int size[2])
{
    //setting size of the map, and initializing the tiles of the map.
    Tiles.resize(size[0]+2);
    rng.seed(5);
    std::normal_distribution<double> normal_dist(1000, 200);

    for(int i = 0; i < size[0]+2; i++)
    {
        Tiles[i].resize(size[1]+2);
        
        for(int j = 0; j < size[1]+2; j++)
        {
            int pos[2] = {i,j};
            
            //This array can be later changed to whatever is needed
            double x[5] = {normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng)};
            bool access = true;
            if(i == 0 || i == size[0] + 1 || j == 0 || j == size[1] + 1)
                access = false;
            
            Tiles[i][j].define(x,pos,access);
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