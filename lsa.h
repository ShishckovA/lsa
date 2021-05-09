#ifndef INTERPOLATION
#define INTERPOLATION
#include "point.h"

class Interpolation {
    private:
        Point *points;
        Real eps;
        int n;
    public:
        Interpolation(Point *points_, int n, Real eps);
        ~Interpolation();
        Real inter_lsa(Real x);
};

#endif  // INTERPOLATION
