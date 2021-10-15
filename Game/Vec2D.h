#pragma once
#include<iostream>
using namespace std;


class Vec2D
{
public:
	static const Vec2D Zero;
	Vec2D():Vec2D(0,0){}
	Vec2D(float x, float y): mX(x),mY(y){}
	 
	inline void SetX(float x) { mX = x;}
	inline void SetY(float y) { mY = y; }
	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }


	bool operator == (const Vec2D& vec2)const;
	bool operator != (const Vec2D& vec2)const;

	Vec2D operator-()const;
	Vec2D operator*(float scale)const;
	Vec2D operator/(float scale)const;
	Vec2D& operator *=(float scale);
	Vec2D& operator /=(float scale);
	Vec2D operator+(const Vec2D& vec)const;
	Vec2D operator - (const Vec2D & vec) const;
	Vec2D &operator += (const Vec2D& vec);
	Vec2D &operator -= (const Vec2D& vec) ;
	friend Vec2D operator*(float scalar, const Vec2D& vec);
	friend ostream& operator<<(ostream& consoleOut, const Vec2D& vec);

	float Magnitude2() const;
	float Magnitude()const;

	Vec2D projectionOnto(const Vec2D& veec2)const ;
	

	Vec2D GEtUnitVec()const; 
	Vec2D& Normalize();
	Vec2D Reflect(const Vec2D& normalVec)const;
	void Rotate(float angle, const Vec2D& aroundPoint);
	Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;

	float Distance(const Vec2D& vec) const;
	float DotProduct(const Vec2D& vec) const;
	float AngleBetween(const Vec2D& vec2) const;



private:
	float mX;
	float mY;
};



