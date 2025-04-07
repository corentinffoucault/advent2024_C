#include <string>

#ifndef POINT2D_H_
#define POINT2D_H_
using namespace std;

class Point2D {
public:
    Point2D(int _x, int _y);
    int getX();
    int getY();
    string toString();
    Point2D operator+(const Point2D& other) const;
    Point2D operator-(const Point2D& other) const;
    Point2D operator*(const int value) const;
    bool operator<(const Point2D& other) const;
    ~Point2D();
private:
    int x;
    int y;
};

class Point2DDirection {
public: 
    static const Point2D North;
    static const Point2D South;
    static const Point2D East;
    static const Point2D West;
    static const Point2D Origin;
};

#endif  /* !POINT2D_H_ */