#include "Starters.h"

using engine = std::default_random_engine;
engine rng(time(0));

class mapTile
{
public:

    int position[2] = {0,0};
    double resources[5];

    //'A' or 'B' for belonging to a team, 'X' for not being accesible
    char status = 'U';
    
    void define(int pos[2], bool access)
    {
        memcpy(position,pos,sizeof(position));

        if(access)
        {
            std::normal_distribution<double> normal_dist(1000, 200);
            double x[5] = {normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng),normal_dist(rng)};
            memcpy(resources,x,sizeof(x));   
        }
        else
        {
            status = 'X';
            double x[5] = {0,0,0,0,0};
            memcpy(resources,x,sizeof(x));
        }
    }

    void resourceDraw(bool isCenter, double *res[5])
    {
        double fraction = 0.2;
        if (isCenter)
            fraction = 0.4;

        double change = 0;
        
        for (int i = 0; i<5; i++)
        {
            change = resources[i]*fraction;
            resources[i] -= change;
            *(res[i]) += change;
        }
    }
};