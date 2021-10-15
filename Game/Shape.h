#pragma once
#include "Vec2D.h"
#include<vector>
using namespace std;
class Shape
{
public:
	virtual Vec2D GetCenterPoint()const = 0;
	virtual ~Shape(){}
	inline virtual vector<Vec2D> GetPoints() const { return mPoints; }
	void MoveBy(const Vec2D& deltaOffset);


protected:
	vector<Vec2D> mPoints;
};

