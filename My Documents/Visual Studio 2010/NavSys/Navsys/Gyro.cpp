/* Edward Morgans
 * CS 1567
 * L3GD20
 * 3-Axis Gyro Module
 * Measures speed of rotation in degrees per second.
 */

#include "Gyro.h"
#include <cmath>
#include <boost/math/constants/constants.hpp>
using namespace Eigen;
using boost::math::constants::pi;

const static double VMax = 5;
const static double Mult = 3;
const static int interval = 50;

Gyro::Gyro(){
	const Eigen::Vector3d up = Eigen::Vector3d(User.get_u());
	const Eigen::Vector3d vp = Eigen::Vector3d(User.get_v());
	const Eigen::Vector3d wp = Eigen::Vector3d(User.get_w());
	rot_speed = Eigen::Vector3d(0,0,0);
}


const Eigen::Vector3d Gyro::get_rot_speed(){
	const Eigen::Vector3d u = User.get_u();
	const Eigen::Vector3d v = User.get_v();
	const Eigen::Vector3d w = User.get_w();

	double psi, theta, phi; //rotations around x, y, z axes

	Matrix<double, 3, 3> rota,rotb,rotc;
	rota << 
		up.x(), up.y(), up.z(),
		vp.x(), vp.y(), vp.z(),
		wp.x(), wp.y(), wp.z();
	rotb <<
		u.x(), v.x(), w.x(),
		u.y(), v.y(), w,y(),
		u.z(), v.z(), w.z();
	rotc = rota * rotb;

	if(fabs(rotc(3,1)) != 1){
		theta = -asin(rotc(3,1));
		psi = atan2(rotc(3,2)/cos(theta),rotc(2,3)/cos(theta));
		phi = atan2(rotc(2,1)/cos(theta),rotc(11)/cos(theta));
	}else{
		phi = 0;
		double delta = atan2(rotc(1,2),rotc(1,3));
		if(rotc(3,1) = -1){
			theta = pi<double>()/2;
			psi = phi + delta;
		}else{
			theta = -pi<double>()/2;
			psi =  -phi + delta;
		}
	}
	double time = (double)interval/1000;
	rot_speed << psi/time,theta/time,phi/time;

	return rot_speed;


}