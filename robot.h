class robot
{
public:

    char team_name;//'A' or 'B'
    int position[2];

    robot(char team);

    void move (char direction);

    char statusSense (char direction);

    void resource_draw();
};