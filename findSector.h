#include <vector>

class Coordinate{
    public:
    float x;
    float y;
};

class Sectors
{
  public:
  float sectorBegin;
  float sectorEnd;
};
class SectorEvaluation
{
    private:
    Sectors sectors_;
    std::vector<Coordinate> coordinates_;
    std::vector<float> angles_;    
    void transformToPolar();
    void setSectorsLimits();
    void normalizedAngles(std::vector<float>& resultAngles);
    void findLimits(const std::vector<float>& angles);
    public:
    Sectors& getSectors(const std::vector<Coordinate>& coordinates);

};