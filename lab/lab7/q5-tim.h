// cody by tim, L7Q5

#define PI 3.1415

void sphere(int r, double *v, double *s) {
    *v = (4.0 / 3.0 * PI * r * r * r);  // volume of a sphere: 4/3*pi*r³
    *s = (4.0 * PI * r * r);            // surface of a sphere: 4*pi*r²
}