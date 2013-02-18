/* Edward Morgans
 * CS 1567
 * LSM303
 * 3-Axis Compass/Accel
 */

#include <Eigen/Core>
#include "User.h"

class Compass {
public:
	compass();
	int get_heading();

private:
	Eigen::Vector2d direction;
	void find_direction();
};