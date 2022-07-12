#include "robot_exec.h"

void initialize_map(int size[2])
{
    //setting size of the map, and initializing the tiles of the map.
    Tiles.resize(size[0]+2);

    for(int i = 0; i < size[0]+2; i++)
    {
        Tiles[i].resize(size[1]+2);
        
        for(int j = 0; j < size[1]+2; j++)
        {
            int pos[2] = {i,j};            
            bool access = true;

            if(i == 0 || i == size[0] + 1 || j == 0 || j == size[1] + 1)
                access = false;

            Tiles[i][j].define(pos,access);
        }
    }    
}



int main()
{
    initialize_map(MAP_DIM); 
    /*Will set up the relevant classes etc., to be executed once:
    This might be present as a separate CPP file at the end, using this project
    as the Update() function instead*/
    // Update() : Assuming the input is a file with inclassions for 
    // change line-wise, this will make those changes one-by one.
    // A lot is left to be figured, but then this is testing git.
}