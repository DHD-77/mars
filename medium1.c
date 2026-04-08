#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    double x, y, z;
} Vec3;

Vec3 transform_to_world(Vec3 p, Vec3 pos, Vec3 rot) {
    Vec3 out;
    double rad_z = rot.z * (M_PI / 180.0);

    // Rotate around Z axis (standard 2D rotation for orientation)
    double x_rot = p.x * cos(rad_z) - p.y * sin(rad_z);
    double y_rot = p.x * sin(rad_z) + p.y * cos(rad_z);
    
    // Apply translation
    out.x = x_rot + pos.x;
    out.y = y_rot + pos.y;
    out.z = p.z + pos.z;

    return out;
}

int main() {
    Vec3 obj_cam = {2.0, 1.0, 3.0};
    Vec3 rover_pos = {10.0, 5.0, 0.0};
    Vec3 rover_rot = {0.0, 0.0, 45.0};

    Vec3 world = transform_to_world(obj_cam, rover_pos, rover_rot);

    printf("World Coordinates: (%.2f, %.2f, %.2f)\n", world.x, world.y, world.z);

    return 0;
}