#ifndef TOPOGRAPHIC_H_  
#define TOPOGRAPHIC_H_  
#include <vector>  
#include <memory>

#include "../../lib/Point2D/Point2D.h"

using namespace std;

class Topographic {
public:
    Topographic(vector<Point2D> _zeros, vector<vector<int>> _map);
    int findAllFullPathFromAllSourceV2();
    int findAllFullPathFromAllSource();
private: 
    vector<Point2D> zeros;
    vector<vector<int>> map;
    int findAllPathFromOnSource(Point2D zero);
    int findAllPathFromOnSourceV2(Point2D zero);
    vector<Point2D> getAllNext(Point2D point);
    void append_vector(shared_ptr<vector<Point2D>> dest, const std::vector<Point2D> src);
};
#endif