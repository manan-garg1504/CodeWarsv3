#include "robot.h"

//will also contain any base code.
class team
{
private:

    char team_name;
    double resources[5];
    std::vector<robot> robots;

public:

    team(char name)
    {
        team_name = name;
        memcpy(resources, STARTING_RESOURCES, sizeof(STARTING_RESOURCES));
    }
};

team TeamA('A'), TeamB('B');