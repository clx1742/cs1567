/* Edward Morgans
 * CS 1567
 * LV-EZ1.cpp
 * Maxbotix Ultrasonic Rangefinder
 */

#include "Ultrasonic.h"
using namespace Eigen;

const static double Vmax = 5;
const static double Dmax = 6;

Ultrasonic::Ultrasonic(double x, double y, double z){
	dir = Vector3d(x,y,z);

}
double Ultrasonic::get_distance()
{
	const Eigen::Vector3d u = User.get_u();
	const Eigen::Vector3d v = User.get_v();
	const Eigen::Vector3d w = User.get_w();

	Matrix<double, 3, 3> rot;
	rot <<
		u.x(), u.y(), u.z(),
		v.x(), v.y(), v.z(),
		w.x(), w.y(), w.z();
	Vector3d sensor_dir = rot * dir;
	return Vmax * (User.nearest_wall(sensor_dir)/Dmax);
}