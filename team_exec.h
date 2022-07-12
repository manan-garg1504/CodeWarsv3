#include "team.h"
#include "robot.h"
#include "mapTile.h"

team::team (char name)
{
    team_name = name;
    memcpy(resources, STARTING_RESOURCES, sizeof(STARTING_RESOURCES));
}

void team::mkRobot(short n)
{
    for(short i = 0; i < n; i++)
    {
        robots.push_back(robot(team_name));
        
        //a proper resource drop is necessary
        resources[1] -= 200;
    }
}

team TeamA('A'), TeamB('B');