#include <cmath>
#include <iostream>

class Circle {
  double radius;
  public:
    Circle(double r) {
      radius = r;
    }

    double circumference() {
      return 2 * M_PI * radius;
    }

    double area() {
      return M_PI * std::pow(radius,2);
    }
};

int main() {
  Circle circ(3);
  std::cout << "circumference: " << circ.circumference() << std::endl;
  std::cout << "area: " << circ.area() << std::endl;
  return 0;
}