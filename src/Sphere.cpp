#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <iostream>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double radius = this->radius;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d o = this->center;

  double a = d.dot(d);
  double b = d.dot(e-o);
  double c = (e-o).dot(e-o) - pow(radius,2);

  double discriminant = pow(b,2) - a * c;

  if (discriminant < 0)
  {
  	return false;
  }
  else if (discriminant >= 0 && discriminant <= 1e-6)
  {
  	t = -b/a;
  }
  else
  {

  	t = (-b - sqrt(discriminant))/a;
  	if (t < min_t)
  	{
  		t = (-b + sqrt(discriminant))/a;
  	}
  }
  if (t<min_t)
  {
  	return false;
  }
  auto intersection = e + t*d;
  n = (intersection-o).normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

