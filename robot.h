#include <cstring>
#include "mapTile.h"


class robot
{
private:
    char team_name;//'A' or 'B'
    int position[2];

public: 

    robot(char team)
    {
        if(team == 'A')
            memcpy(position,BASE_A,sizeof(BASE_A));
        else
            memcpy(position,BASE_B,sizeof(BASE_B));
    }

    void move (char direction)
    {
        if(direction == 'U' && Tiles[position[0]][position[1]-1].ownership !='X')
            position[1] -=1;
        if(direction == 'D' && Tiles[position[0]][position[1]+1].ownership !='X')
            position[1] +=1;
        if(direction == 'R' && Tiles[position[0]+1][position[1]].ownership !='X')
            position[0] +=1;
        if(direction == 'L' && Tiles[position[0]-1][position[1]].ownership !='X')
            position[0] -=1;
    }
};