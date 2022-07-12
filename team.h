class robot;
#include <vector>

//will also contain any base code.
class team
{
public:

    std::vector<robot> robots;
    double resources[5];
    char team_name;

    team(char name);

    void mkRobot(short n);
};