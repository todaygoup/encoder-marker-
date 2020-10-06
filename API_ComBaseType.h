#ifndef API_COMBASETYPE_H
#define API_COMBASETYPE_H


struct EllipseMarker
{
    int id = -1;
    double center_x;
    double center_y;
    double semi_long_axis;
    double semi_short_axis;
    double major_axis_off_angle;
    double accuracy_of_center_x;
    double accuracy_of_center_y;
};	

struct Marker3D
{
    int id;
    double x;
    double y;
    double z;
};

struct Point2D
{
    double x;
    double y;
};

struct Conic2D
{
    double c_a2;
    double c_ab;
    double c_b2;
    double c_a;
    double c_b;
    double c_1;
};

struct ConicMatrix
{
    union {
        double Mtx[9];
        double c11, c12, c13, c21, c22, c23, c31, c32, c33;
    };
};

struct Line2D
{
    double c_x, c_y, c_1;
};

#endif
