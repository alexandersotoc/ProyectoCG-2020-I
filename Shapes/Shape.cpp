#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"
#include "Special.h"

void Shape::solidColor()
{
    colors.clear();

    for(int i=0;i<vertices.size();i++){
        colors.append(QVector3D(1,1,0));
    }
}

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
