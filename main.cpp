#include <iostream>
#include "findSector.h"



int main(){
    SectorEvaluation sectorEvaluation;
    std::vector<Coordinate> coord;
        Coordinate c;
        /*
        c.x=1;
        c.y=1;
        coord.push_back(c);

        c.x=1;
        c.y=3;
        coord.push_back(c);
        
        c.x=4;
        c.y=1;
        coord.push_back(c);*/
/*
        c.x=3;
        c.y=4;
        coord.push_back(c);

        c.x=4;
        c.y=0;
        coord.push_back(c);

        c.x=10;
        c.y=8;
        coord.push_back(c);
*/
        c.x=-1;
        c.y=1;
        coord.push_back(c);

        c.x=-1;
        c.y=-3;
        coord.push_back(c);
        
        c.x=-1;
        c.y=-1;
        coord.push_back(c);
        Sectors sectors = sectorEvaluation.getSectors(coord);
        std::cout<<"SectorBegin: "<<sectors.sectorBegin<<"\n";
        std::cout<<"SectorEnd: "<<sectors.sectorEnd<<"\n";
    return 0;
}
