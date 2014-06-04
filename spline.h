#ifndef SPLINE_H
#define SPLINE_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef vector<double> vec;

struct SplineSet{
    double a;
    double b;
    double c;
    double d;
    double x;
};

vector<SplineSet> CalculateSpline(vec &x, vec &y);

#endif // SPLINE_H
