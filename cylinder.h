#include "constants.h"

class Cylinder {
   private: // private is the default
    double radius {};
    double height {};

  // constructors
  public:
    Cylinder() {
      radius = 1.0;
      height = 1.0;
    }

    Cylinder(double r, double h);

  public:
    double volume();
    double getHeight();
    double getRadius();
    void setHeight(double h);
    void setRadius(double r);
};