#include <GL/freeglut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

typedef struct vector{
    float x;
    float y; 
    float z;
}vector;
void print_vector(vector r);
float dot_product(vector a, vector b);
float cos_angle(vector a, vector b);
vector difference(vector a, vector b);
vector sum(vector a, vector b);
vector cross_product(vector a, vector b);
vector normalization(vector p);
vector find_normal(vector p1, vector p2, vector p3);
vector center(vector points[], int size);
float intensity(vector p1, vector p2, vector p3, vector source);
