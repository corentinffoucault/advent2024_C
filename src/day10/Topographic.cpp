#include <numeric>
#include <set>

#include "Topographic.h";
#include <locale>

Topographic::Topographic(vector<Point2D> _zeros, vector<vector<int>> _map) {
    this->zeros = _zeros;
    this->map = _map;
}

int Topographic::findAllFullPathFromAllSource() {
    return accumulate(zeros.cbegin(), zeros.cend(), 0, [this](int sum, const Point2D& zero) {
        return sum+findAllPathFromOnSource(zero);
        });
}

int Topographic::findAllFullPathFromAllSourceV2() {
    return accumulate(zeros.cbegin(), zeros.cend(), 0, [this](int sum, const Point2D& zero) {
        return sum+findAllPathFromOnSourceV2(zero);
        });
}

int Topographic::findAllPathFromOnSource(Point2D zero) {  
   shared_ptr<set<Point2D>> currentPoints = make_shared<set<Point2D>>(set<Point2D>{ zero });  
   int index = 0;  
   while (index < 9) {  
       shared_ptr<set<Point2D>> seen = make_shared<set<Point2D>>();  
       for (Point2D point : *currentPoints) {  
           vector<Point2D> s2 = getAllNext(point);  
           seen->insert(s2.begin(), s2.end());  
       }  
       index++;  
       currentPoints = seen;  
   }  
   return currentPoints->size();  
}

int Topographic::findAllPathFromOnSourceV2(Point2D zero) {
    shared_ptr<vector<Point2D>> currentPoints = make_shared<vector<Point2D>>(vector<Point2D>{ zero });
    int index = 0;
    while (index < 9) {
        shared_ptr<vector<Point2D>> nextPoints = make_shared<vector<Point2D>>();
        for (Point2D point: *currentPoints) {
            vector<Point2D> s2 = getAllNext(point);
            nextPoints->insert(nextPoints->end(), s2.begin(), s2.end());
        }
        index++;
        currentPoints = nextPoints;
    }
    return currentPoints->size();
}

vector<Point2D> Topographic::getAllNext(Point2D point) {
    int value = map[point.getY()][point.getX()];
    vector<Point2D> nextPoints;

    if (point.getX()> 0 && map[point.getY()][point.getX()- 1] == value + 1) {
        nextPoints.push_back(Point2D(point.getX() - 1, point.getY()));
    }
    if (point.getX()< map[0].size() - 1 && map[point.getY()][point.getX() + 1] == value + 1) {
        nextPoints.push_back(Point2D(point.getX() + 1, point.getY()));
    }
    if (point.getY() > 0 && map[point.getY() - 1][point.getX()] == value + 1) {
        nextPoints.push_back(Point2D(point.getX(), point.getY() - 1));
    }
    if (point.getY() < map.size() - 1 && map[point.getY() + 1][point.getX()] == value + 1) {
        nextPoints.push_back(Point2D(point.getX(), point.getY() + 1));
    }
    return nextPoints;
}