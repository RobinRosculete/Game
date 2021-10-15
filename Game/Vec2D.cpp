#include "Vec2D.h"
#include "Vec2DHelper.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

ostream& operator<<(ostream& consoleOut, const Vec2D& vec)
{
consoleOut << "X:" << vec.mX << " Y:" << vec.mY << endl;
return consoleOut;
}

bool Vec2D::  operator == (const Vec2D& vec2)const {
	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D:: operator != (const Vec2D& vec2)const {

	return !(*this== vec2);
}


Vec2D Vec2D:: operator-()const {
	return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator* (float scale)const {
	return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/ (float scale)const {
	assert(fabs(scale) > EPSILON);
	return Vec2D(mX/scale, mY / scale);
}

Vec2D& Vec2D:: operator *=(float scale)  {

	*this = *this * scale;
	return *this;
}

Vec2D& Vec2D:: operator /=(float scale) {

	*this = *this / scale;
	return *this;
}

Vec2D operator*(float scalar, const Vec2D& vec) {

	return vec * scalar;
}

Vec2D Vec2D:: operator+(const Vec2D& vec)const {

	return Vec2D(mX + vec.mX, mY + vec.mY);
}

Vec2D Vec2D:: operator - (const Vec2D& vec) const {

	return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D &Vec2D:: operator += (const Vec2D& vec) {
	*this = *this + vec;
	return *this;
}

Vec2D &Vec2D:: operator -= (const Vec2D& vec) {
	*this = *this - vec;
	return *this;
}

//Calculating only the sum of the squares
float Vec2D:: Magnitude2() const {
	return DotProduct(*this);

}

//Calculatig the magnitude
float Vec2D:: Magnitude()const {
	return sqrt(Magnitude2());
}

Vec2D Vec2D:: GEtUnitVec()const {
	float mag = Magnitude();

	if (mag > EPSILON)
		return *this / mag;

	return Vec2D::Zero;
}

Vec2D& Vec2D:: Normalize() {
	float mag = Magnitude();
	if (mag > EPSILON)
		 *this /= mag;

	return*this;
}

float Vec2D:: Distance(const Vec2D& vec) const {
	return (vec - *this).Magnitude();
}

float Vec2D:: DotProduct(const Vec2D& vec) const {
	return mX * vec.mX + mY * vec.mY;
}

Vec2D Vec2D:: projectionOnto(const Vec2D& vec2)const {
	float mag2 = vec2.Magnitude2();
	Vec2D unitVec2 = vec2.GEtUnitVec();
	float dot = DotProduct(unitVec2);


	return unitVec2 * dot;
}

float Vec2D:: AngleBetween(const Vec2D& vec2) const {
	return acosf(GEtUnitVec().DotProduct(vec2.GEtUnitVec()));
}

Vec2D Vec2D:: Reflect(const Vec2D& normalVec)const {
	//v-2(v dot n)n

	return *this - 2 * projectionOnto(normalVec);

}

void Vec2D:: Rotate(float angle, const Vec2D& aroundPoint) {
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;
	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);

	*this = rot + aroundPoint;
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const {

	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;
	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D rot = Vec2D(xRot, yRot);

	return rot + aroundPoint;
}
