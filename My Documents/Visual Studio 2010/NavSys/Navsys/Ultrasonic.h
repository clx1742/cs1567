/* Edward Morgans
* CS 1567
* LV-EZ1.h
* Maxbotix Ultrasonic Rangefinder
*/

#include <Eigen/Core>
#include "User.h"



class Ultrasonic {
public:
	const static double Vmax;
	const static double Dmax;
	Ultrasonic(double x, double y, double z);
	double get_distance();
private:
	Eigen::Vector3d dir;
	double distance;
};