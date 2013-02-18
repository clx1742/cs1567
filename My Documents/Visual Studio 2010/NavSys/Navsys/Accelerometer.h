/* Edward Morgans
* CS 1567
* ADLX33
* 3-Axis Accelerometer Module
*/


#include <Eigen/Core>
#include "User.h"

class Accelerometer {
public:
	const static Eigen::Vector3d GRAV;
	const static double VMax;
	const static double Mult;
	Accelerometer();
	const Eigen::Vector3d get_accel();

private:
	Eigen::Vector3d Vaccel;
};