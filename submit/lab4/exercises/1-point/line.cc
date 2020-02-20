#include "line.hh"
#include "point.hh"

#include <string>
#include <sstream>


double Line::length() const{
	return p1.distance(p2);
}

std::string Line::toString() const{
	std::stringstream s;
	s << p1.toString() << "--" << p2.toString();
	return s.str();
}
