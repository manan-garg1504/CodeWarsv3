#include "robot.h"

//will also contain any base code.
class team
{
private:

    char team_name;
    double *resources = STARTING_RESOURCES;
    std::vector<robot> robots;

public:

    team(char name)
    {
        team_name = name;
    }
};