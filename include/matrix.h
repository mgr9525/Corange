#ifndef matrix_h
#define matrix_h

#include "vector.h"

typedef struct {
  
  float xx; float xy; float xz;
  float yx; float yy; float yz;
  float zx; float zy; float zz;
  
} matrix_3x3;


typedef struct {

  float ww; float wx; float wy; float wz;
  float xw; float xx; float xy; float xz;
  float yw; float yx; float yy; float yz;
  float zw; float zx; float zy; float zz;

} matrix_4x4;


/* 3 x 3 */

matrix_3x3 m33_id();
matrix_3x3 m33_zero();
matrix_3x3 m33_mul_m33(matrix_3x3 m1, matrix_3x3 m2);

matrix_4x4 m33_to_m44(matrix_3x3 m);

void m33_to_array(matrix_3x3 m, float* out);
void m33_print(matrix_3x3 m);

/* 4 x 4 */

matrix_4x4 m44_id();
matrix_4x4 m44_zero();
matrix_4x4 m44_transpose(matrix_4x4 m);

matrix_4x4 m44_mul_m44(matrix_4x4 m1, matrix_4x4 m2);

vector4 m44_mul_v4(matrix_4x4 m, vector4 v);


matrix_3x3 m44_to_m33(matrix_4x4 m);

void m44_to_array(matrix_4x4 m, float* out);
void m44_to_array_trans(matrix_4x4 m, float* out);

void m44_print(matrix_4x4 m);

matrix_4x4 m44_translation(vector3 v);
matrix_4x4 m44_scale(vector3 v);
matrix_4x4 m44_rotation(vector3 v);

matrix_4x4 m44_rotation_x(float a);
matrix_4x4 m44_rotation_y(float a);
matrix_4x4 m44_rotation_z(float a);

matrix_4x4 m44_rotation_quaternion(vector4 q);

matrix_4x4 m44_view_look_at(vector3 position, vector3 target, vector3 up);
matrix_4x4 m44_perspective(float fov, float near_clip, float far_clip, float ratio);



#endif