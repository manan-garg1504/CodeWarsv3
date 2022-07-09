#include "Starters.h"

class mapTile
{
private:

    int position[2] = {0,0};
    //can be 'A' or 'B' for belonging to a team, 'X' for not being accesible
    double resources[5];

public:

    char ownership = 'U';
    
    void define(double res[5], int pos[2], bool access)
    {
        memcpy(position,pos,sizeof(position));
        memcpy(resources,res,sizeof(resources));
        if(!access)
            ownership = 'X';
    }
};

std::vector<std::vector<mapTile>> Tiles;