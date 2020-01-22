#include "first_hit.h"
#include <iostream>
#include <limits>

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  
  double cloest = std::numeric_limits<double>::infinity();
  double tmp_t;
  Eigen::Vector3d tmp_n;
  hit_id = -1;
  for (int i = 0; i < objects.size(); ++i)
  {
    if (objects[i]->intersect(ray, min_t, tmp_t, tmp_n))
    {
      if (tmp_t < cloest)
      {
        cloest = tmp_t;
        t = tmp_t;
        n = tmp_n;
        hit_id = i;
      }
    }
  }
  return (hit_id>=0);
  ////////////////////////////////////////////////////////////////////////////
}

