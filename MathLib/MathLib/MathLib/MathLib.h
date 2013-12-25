#ifndef SXMATHLIB
#define SXMATHLIB
#include <iostream>
#include <vector>
using namespace std;
class SXPoint2D;
class SXBasePoint
{
public:
	friend SXPoint2D;
	SXBasePoint(int iPointCount);
	SXBasePoint(const SXBasePoint& PointObj);
	SXBasePoint operator +(float fValue);
	friend SXBasePoint operator +(float fValue,const SXBasePoint& PointObj);
protected:
	vector<float> m_PointList;
};

class SXPoint2D:public SXBasePoint
{
public:
	SXPoint2D():SXBasePoint(2),x(m_PointList[0]),y(m_PointList[1]){}
	SXPoint2D(const SXBasePoint& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]){}
	SXPoint2D& operator =(const SXBasePoint &PointObj);
	float &x,&y;
};
#endif