#include "team.h"

class mapTile
{
private:

    int position[2] = {0,0};
    //can be 'A' or 'B' for belonging to a team.
    char ownership = 'U';

public:
    double *resources;

};