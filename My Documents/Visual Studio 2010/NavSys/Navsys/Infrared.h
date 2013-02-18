/* Edward Morgans
 * CS 1567
 * GP2Y0A02YK
 * Sharp IR Distance Sensor
 */
#include <Eigen/Core>
#include "User.h"


class Infrared {
public:
	const static double Vmax;
	const static double Dmax;
	Infrared(double x, double y, double z);
	double get_distance();
private:
	Eigen::Vector3d dir;
	double distance;
};