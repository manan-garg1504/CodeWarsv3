#include "team_exec.h"

std::vector<std::vector<mapTile>> Tiles;

robot::robot(char team)
{
    if(team == 'A')
        memcpy(position,BASE_A,sizeof(BASE_A));
    else
        memcpy(position,BASE_B,sizeof(BASE_B));

    team_name = team;
}

void robot::move(char direction)
{
    if(direction == 'U' && Tiles[position[0]][position[1]-1].status !='X')
        position[1] -=1;
    if(direction == 'D' && Tiles[position[0]][position[1]+1].status !='X')
        position[1] +=1;
    if(direction == 'R' && Tiles[position[0]+1][position[1]].status !='X')
        position[0] +=1;
    if(direction == 'L' && Tiles[position[0]-1][position[1]].status !='X')
        position[0] -=1;
}

char robot::statusSense(char direction)
{
    char status = '?';

    if(direction == '0')
        status = Tiles[position[0]][position[1]].status;
    if(direction == '1')
        status = Tiles[position[0]+1][position[1]].status;
    if(direction == '2')
        status = Tiles[position[0]+1][position[1]-1].status;
    if(direction == '3')
        status = Tiles[position[0]][position[1]-1].status;
    if(direction == '4')
        status = Tiles[position[0]-1][position[1]-1].status;
    if(direction == '5')
        status = Tiles[position[0]-1][position[1]].status;
    if(direction == '6')
        status = Tiles[position[0]-1][position[1]+1].status;
    if(direction == '7')
        status = Tiles[position[0]][position[1]+1].status;
    if(direction == '8')
        status = Tiles[position[0]+1][position[1]+1].status;

    return status;
}

void robot::resource_draw()
{
    double res[5] = {0,0,0,0,0};
    double *send_res[5] = {&res[0],&res[1],&res[2],&res[3],&res[4]};
    Tiles[position[0]][position[1]].resourceDraw(true,send_res);
    Tiles[position[0]+1][position[1]].resourceDraw(false,send_res);
    Tiles[position[0]+1][position[1]+1].resourceDraw(false,send_res);
    Tiles[position[0]][position[1]+1].resourceDraw(false,send_res);
    Tiles[position[0]-1][position[1]+1].resourceDraw(false,send_res);
    Tiles[position[0]-1][position[1]].resourceDraw(false,send_res);
    Tiles[position[0]-1][position[1]-1].resourceDraw(false,send_res);
    Tiles[position[0]][position[1]-1].resourceDraw(false,send_res);
    Tiles[position[0]+1][position[1]-1].resourceDraw(false,send_res);

    char team_get = 'A';

    if (statusSense('0') == 'X' || statusSense('0') == team_name)
        team_get = team_name;
    else
    {
        std::uniform_int_distribution<int> prob(0,9);

        if(prob(rng) == 0)
            team_get = team_name;
        else if(team_name == 'B')
            team_get = 'B';
    }

    if(team_get == 'A')
    {
        for (int i = 0; i<5; i++)
            TeamA.resources[i] += res[i];
    }
    else
    {
        for(int i = 0; i < 5; i++)
            TeamB.resources[i] += res[i];
    }
}