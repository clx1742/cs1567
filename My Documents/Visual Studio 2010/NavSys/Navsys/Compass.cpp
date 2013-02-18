/* Edward Morgans
 * CS 1567
 * LSM303.cpp
 * 3-Axis Compass/Accel
 */

#include "Compass.h"
#include <boost/math/constants/constants.hpp>
using namespace Eigen;
using boost::math::constants::pi;

const int offset = 20; //offset to rotate person's orientation in the building to the earth's cardinal directions;

Compass::Compass(){
	this->find_direction();
}

int Compass::get_heading(){
	this->find_direction();
	return atan2(direction.x(),direction.y());
}

void Compass::find_direction(){
	direction << User.get_v().x(), User.get_v().y();
	direction.normalize();
}