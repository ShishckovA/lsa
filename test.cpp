#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "l_exception.h"
#include "lsa.h"
#include "my_math.h"
#include "point.h"

static void test(Point *vec, int n, Real x, Real expected_result, int expected_error, const char *message) {
    int error = NA_OK;
    Interpolation *points;
    points = new Interpolation(vec, n, EPS);
    Real result = 0;
    try {
        result = points -> inter_lsa(x);
        printf("Interpolated value = %lf\n", result);
    }   catch (L_exception &err) {
        error = err.code();
    }
    delete points;
    if (expected_error != error) {
        printf("******* Test FAILED! WRONG ERROR_CODE******* %s\nRight ERROR = %d, Your error = %d\n", message, expected_error, error);
        return;
    }
    if (expected_error == error && error != NA_OK) {
        printf("Test OK! Right error!\n");
        return;
    }
    if (compareReal(result, expected_result, EPS) == 0) {
        printf("Test OK!\n");
        return;
    } else {
        printf("******* Test FAILED! WRONG ANSWER******* %s\nRight answer = %lf, Your answer = %lf\n", message, expected_result, result);
        return;
    }
}

int main() {
    Point points1[] = {{0, -1}, {1, 1}, {4, 1}};  // функция f(x) = 0.384615 * x - 0.307692
    test(points1, 3, 2, 0.461538, NA_OK, "Test 1");
    Point points2[] = {{0, -1}, {1, 1}, {4, 1}};  // функция f(x) = 0.384615 * x - 0.307692
    test(points2, 3, 5, 1.61538461, NA_OK, "Test 2");
    Point points3[] = {{0, -1}, {0, -1}, {4, 1}};
    test(points3, 3, 2, 2, NA_ABSCISSA , "Test 3");
    Point points4[] = {{0, -1}};
    test(points4, 1, 2, 2, NA_TOO_LITTLE, "Test 4");
    return 0;
}
