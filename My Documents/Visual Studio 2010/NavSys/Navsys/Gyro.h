/* Edward Morgans
 * CS 1567
 * L3GD20
 * 3-Axis Gyro Module
 */

#include <Eigen/Core>
#include "User.h"

class Gyro {
public:
	Gyro();
	const Eigen::Vector3d get_rot_speed();
	const static int interval;

private:
	Eigen::Vector3d rot_speed;
	Eigen::Vector3d up, vp, wp;
};