#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  auto e = ray.origin;
  auto d = ray.direction;
  auto p = this.point;
  auto normal = this.normal;

  double numerator = (p-e).dot(normal);
  double denumerator = d.dot(normal);

  if (denumerator >= 0 && denumerator <= 1e-6)
  {
  	if (numerator >= 0 && numerator <= 1e-6)
  	{
  		t = min_t;
  		n = normal;
  		return true;
  	}
  	else
  	{
  		return false;
  	}

  }
  t = numerator/denumerator;
  if (t > min_t)
  {
  	n = normal;
  	return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

