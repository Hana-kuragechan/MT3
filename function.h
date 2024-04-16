#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <Novice.h>

struct Vector3 {
	float x, y, z;
};

Vector3 Add(const Vector3&v1,const Vector3&v2);
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
Vector3 Multiply(float scalar, const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);
float Length(const Vector3& v);
Vector3 Normalize(const Vector3& v);
static const int kColumnWidth = 60;
void VectorScreenprintf(int x, int y, const Vector3& vector, const char* label);