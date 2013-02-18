/* Edward Morgans
 * CS 1567
 * ADLX335
 * 3-Axis Accelerometer Module
 */


#include "Accelerometer.h"
using namespace Eigen;

const static double VMax = 5;
const static double Mult = 3;

Accelerometer::Accelerometer(){
	Eigen::Vector3d GRAV(0,-9.81,0);
}


const Eigen::Vector3d Accelerometer::get_accel(){
	const Eigen::Vector3d u = User.get_u();
	const Eigen::Vector3d v = User.get_v();
	const Eigen::Vector3d w = User.get_w();

	Vaccel(0) = GRAV.dot(u);
	Vaccel(1) = GRAV.dot(v);
	Vaccel(2) = GRAV.dot(w);

	Vaccel = Vaccel * (VMax/(Mult*GRAV(2)));

	return Vaccel;


}