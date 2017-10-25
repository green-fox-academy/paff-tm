#include <stdio.h>

typedef struct rectangular_cuboid {
    double a;
    double b;
    double c;
} t_RecCub;

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

double GetSurface(t_RecCub RecCub);
double GetVolume(t_RecCub RecCub);

int main()
{
    t_RecCub rc;

    printf("a, b, c: ");
    scanf("%lf, %lf, %lf", &rc.a, &rc.b, &rc.c);
    fflush(stdin);

    printf("surface: %g\n", GetSurface(rc));
    printf("volume: %g\n", GetVolume(rc));

    return 0;
}

double GetSurface(struct rectangular_cuboid RecCub)
{
    double result = 2 * ((RecCub.a * RecCub.b) + (RecCub.a * RecCub.c) + (RecCub.b * RecCub.c));
    return result;
}


double GetVolume(struct rectangular_cuboid RecCub)
{
    return (RecCub.a * RecCub.b * RecCub.c);
}
