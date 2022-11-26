#include <stdio.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
} Point;

void printPoint(Point point);
Point createPoint(double x, double y);
double getDistance (Point p1, Point p2);

int main()
{
    Point p0;
    printPoint(p0);
    
    // Point p1 = {2.0, -3.0}, p2 = {-4.0, 5.0}; // a)

    // Point p1 = createPoint(2.0, -3.0);  // c)
    // Point p2 = createPoint(-4.0, 5.0);  // c)

    // printPoint(p1); // b)
    // printPoint(p2); // b)

    // double distance = getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));  // d)
    // printf("Distance between points is %.1lf\n", distance);

    return 0;
}

void printPoint(Point point)
{
    printf("(%.1lf, %.1lf)\n", point.x, point.y);
}

Point createPoint(double x, double y)
{
    Point point = {x, y};
    return point;
}

double getDistance (Point p1, Point p2)
{
    double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return distance;
}