#include "cylinder.h"
Cylinder::Cylinder(double r, double h) {
  radius = r;
  height = h;
}

double Cylinder::volume() {
  return PI * radius * radius * height;
}

double Cylinder::getHeight() {
  return height;
}

double Cylinder::getRadius() {
  return radius;
}

void Cylinder::setHeight(double h) {
  height = h;
}

void Cylinder::setRadius(double r) {
  radius = r;
}