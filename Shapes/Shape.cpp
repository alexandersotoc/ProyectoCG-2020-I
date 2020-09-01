#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include "Special.h"

Shape *Shape::chooseShape(int choice) {
    if (choice == 1)
        return new Cube;
    else if (choice == 2)
        return new Cylinder;
    else if (choice == 3)
        return new Cone;
    else if (choice == 4)
        return new Sphere;
    else 
        return new Special;
}
