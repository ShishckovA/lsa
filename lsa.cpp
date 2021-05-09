#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "l_exception.h"
#include "lsa.h"
#include "my_math.h"
#include "point.h"


using namespace std;

Interpolation::Interpolation(Point *points_, int n, double eps) {
    this -> points = new Point[n];
    this -> eps = eps;
    this -> n = n;

    for (int i = 0; i < n; i++) {
        (this -> points)[i] = points_[i];
    }

    qsort(this -> points, n, sizeof(Point), Point::compare);
}

Real Interpolation::inter_lsa(Real x) {
    if (n < 2) {
        throw L_exception(NA_TOO_LITTLE, "Too little points to compute");
    }

    for (int j = 0; j < n - 1; j++) {
        if (compareReal((this -> points)[j].get_X(), (this -> points)[j + 1].get_X(), eps) == 0) {
            throw L_exception(NA_ABSCISSA, "Two points have equal abscissa");
        }
    }

    Real s = 0, q = 0, z = 0, p = 0;
    for (int i = 0; i < n; ++i) {
        Real x = this -> points[i].get_X();
        Real y = this -> points[i].get_Y();
        s += x;
        q += x * x;
        z += y;
        p += x * y;
    }

    Real A = (this -> n * p - s * z) / (this -> n * q - s * s);
    Real B = (q * z - p * s) / (this -> n * q - s * s);

    return A * x + B;
}

Interpolation::~Interpolation() {
    delete[] (this -> points);
}
