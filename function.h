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

struct Sphere
{
	Vector3 center;
	float radius;
};

struct Line
{
	Vector3 origin;
	Vector3 diff;
};
struct Ray
{
	Vector3 origin;
	Vector3 diff;
};
struct Segment
{
	Vector3 origin;
	Vector3 diff;
};
struct Plane
{
	Vector3 normal;
	float distance;
};
struct  Triangle
{
	Vector3 vertices[3];
};

struct AABB {
	Vector3 min;
	Vector3 max;
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
static const int kWindowWidth = 1280;
static const int kWindowHeight = 720;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix);


Matrix4x4 MakeTranslateMatrix(Vector3 translate);
Matrix4x4 MakeScaleMatrix(Vector3 scale); 
Matrix4x4 MakeRotateXMatrix(float radian);
Matrix4x4 MakeRotateYMatrix(float radian);
Matrix4x4 MakeRotateZMatrix(float radian);
Matrix4x4 MakeRotateMatrix(Vector3 radian);
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

Vector3 Project(const Vector3& v1, const Vector3& v2);
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

bool IsCollision(const Sphere& s1, const Sphere& s2);//球と球
bool IsCollision(const Sphere& s, const Plane& p);//球と平面
bool IsCollision(const Segment& s, const Plane& p);
bool IsCollision(const Triangle& t, const Segment& s);
bool IsCollision(const AABB& aabb1, const AABB& aabb2);

Vector3 Perpendicular(const Vector3& v);
void DrawPlane(const Plane& p, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
void DrawTriangle(const Triangle& t, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewportMatrix, uint32_t color);