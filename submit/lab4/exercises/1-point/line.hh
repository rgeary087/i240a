#ifndef LINE_HH_
#define LINE_HH_

#include <string>
#include "point.hh"

struct Line{
	Point p1,p2;
	Line(Point p1 = Point(0,0), Point p2 = Point(0,0)): p1(p1), p2(p2){}

	double length() const;

	std::string toString() const;
};
#endif
