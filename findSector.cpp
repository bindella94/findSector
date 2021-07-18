#include "findSector.h"
#include <math.h>
#include <iostream>
   Sectors& SectorEvaluation::getSectors(const std::vector<Coordinate>& coordinates)
    {
        coordinates_=coordinates;
        transformToPolar();
        setSectorsLimits();
       
        return sectors_;
    }
    void SectorEvaluation::transformToPolar(){
        for (auto points : coordinates_){
            angles_.push_back(std::atan2(points.y,points.x)*180.0f/3.1457f);
        }
    }
    void SectorEvaluation::setSectorsLimits(){
        sectors_.sectorBegin=angles_.at(0);
        sectors_.sectorEnd=angles_.at(0);

        findLimits(angles_);
        if(sectors_.sectorBegin>90 && sectors_.sectorEnd<-90){
            std::vector<float> normAngles;
            normalizedAngles(normAngles);
            findLimits(normAngles);
            if(sectors_.sectorBegin>=180){
                sectors_.sectorBegin-=360.0f;
            }
            if(sectors_.sectorEnd>=180){
                sectors_.sectorEnd-=360.0f;
            }
        }
    }

    void SectorEvaluation::normalizedAngles(std::vector<float>& resultAngles){
        for(auto angle: angles_){
            if(angle>=0){
                resultAngles.push_back(angle);
            }
            else{
                resultAngles.push_back(360.0f+angle);
            }
        }
    }

    void SectorEvaluation::findLimits(const std::vector<float>& angles){
            for(auto angle : angles){
            if(sectors_.sectorBegin>angle){
                sectors_.sectorBegin=angle;
                //std::cout<<"Setted a new max"<<angle<<"\n";
            }
            if(sectors_.sectorEnd<angle){
                sectors_.sectorEnd=angle;
                //std::cout<<"Setted a new min"<<angle<<"\n";
            }
        }
    }