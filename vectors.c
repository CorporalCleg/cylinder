#include "vectors.h"

void print_vector(vector r)
{
    printf("nx%f\n", r.x);
    printf("ny%f\n", r.y);
    printf("nz%f\n", r.z);

}

float dot_product(vector a, vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float cos_angle(vector a, vector b)
{
    return dot_product(a, b) / (dot_product(a, a) * dot_product(b, b));
}

vector difference(vector a, vector b)
{
    vector d;

    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;

    return d;

}

vector sum(vector a, vector b)
{
    vector d;

    d.x = a.x + b.x;
    d.y = a.y + b.y;
    d.z = a.z + b.z;

    return d;

}

vector cross_product(vector a, vector b)
{
    vector m;
    m.x = a.y * b.z - a.z * b.y;
    m.y = a.z * b.x - a.x * b.z; 
    m.z = a.x * b.y - a.y * b.x;
    return m;
}

vector normalization(vector p)
{
    vector pn;
    float c = sqrt(dot_product(p, p));

    pn.x = p.x / c;
    pn.y = p.y / c;
    pn.z = p.z / c;

    return pn;
}

vector find_normal(vector p1, vector p2, vector p3)
{
    return(normalization(cross_product(difference(p1, p2), difference(p2, p3))));
}

vector center(vector points[], int size)
{
    vector s;
    s.x = s.y = s.z = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        s.x += points[i].x;
        s.y += points[i].y;
        s.z += points[i].z;
    }

    s.x /= size;
    s.y /= size;
    s.z /= size;

    return s;

}

float intensity(vector p1, vector p2, vector p3, vector source)
{
    vector c[] = {p1, p2, p3};
    float result = dot_product(find_normal(p1, p2, p3), normalization(difference(source, center(c, 3))));
    if (result < 0)
        return 0;
    return result;
}