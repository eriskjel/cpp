//
// Created by eriks on 07.09.2023.
//

#ifndef OVING_3_CIRCLE_H
#define OVING_3_CIRCLE_H
const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;
private:
    double radius;
};
#endif //OVING_3_CIRCLE_H
