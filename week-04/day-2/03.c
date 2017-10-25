#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

// TODO:
// Create a function that constructs a point
// It should take it's x and y coordinate as parameter

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them

point_t func(int x, int y);
float dist(point_t point_1, point_t point_2);

int main()
{
    int x, y;
    point_t p1, p2;

    printf("x1, y1: ");
    scanf("%d, %d", &x, &y);
    fflush(stdin);
    p1 = func(x, y);

    printf("x2, y2: ");
    scanf("%d, %d", &x, &y);
    fflush(stdin);
    p2 = func(x, y);

    printf("%g", dist(p1, p2));

    return 0;
}

point_t func(int x, int y)
{
    point_t p;

    p.x = x;
    p.y = y;

    return p;
}

float dist(point_t point_1, point_t point_2)
{
    int x = point_1.x - point_2.x;
    int y = point_1.y - point_2.y;

    return sqrt(pow(x, 2) + pow(y, 2));
}
