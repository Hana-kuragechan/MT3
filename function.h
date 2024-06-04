#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <assert.h>
#include <Novice.h>

struct Vector3 {
	float x, y, z;
};
struct Matrix4x4
{
	float m[4][4];
};

Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
Vector3 Multiply(float scalar, const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);
float Length(const Vector3& v);
Vector3 Normalize(const Vector3& v);
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
static const int kColumnWidth = 60;
void VectorScreenprintf(int x, int y, const Vector3& vector, const char* label);

Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 Inverse(const Matrix4x4& m);
Matrix4x4 Transpose(const Matrix4x4& m);
Matrix4x4 MakeIdetity4x4();

static const int kRowHeight = 20;
static const int kRColumnWidth = 60;
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix);


Matrix4x4 MakeTranslateMatrix(Vector3 translate);
Matrix4x4 MakeScaleMatrix(Vector3 scale); 
Matrix4x4 MakeRotateXMatrix(float radian);
Matrix4x4 MakeRotateYMatrix(float radian);
Matrix4x4 MakeRotateZMatrix(float radian);
Matrix4x4 MakeRotateMatrix(Vector3 radian);