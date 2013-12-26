#ifndef SXMATHLIB
#define SXMATHLIB
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define PRECISION 0.000001
bool SXMathFloatIsEqual(float fx,float fy);

class SXBasePoint
{
public:
	SXBasePoint(int iPointCount);
	SXBasePoint(const SXBasePoint& PointObj);
	SXBasePoint operator +(float fValue);
	friend SXBasePoint operator +(float fValue,const SXBasePoint& PointObj);
	SXBasePoint operator -(float fValue);
	friend SXBasePoint operator -(float fValue,const SXBasePoint& PointObj);
	SXBasePoint operator *(float fValue);
	friend SXBasePoint operator *(float fValue,const SXBasePoint& PointObj);
	SXBasePoint operator /(float fValue);
	friend SXBasePoint operator /(float fValue,const SXBasePoint& PointObj);
	SXBasePoint& operator +=(float fValue);
	SXBasePoint& operator -=(float fValue);
	SXBasePoint& operator *=(float fValue);
	SXBasePoint& operator /=(float fValue);
	SXBasePoint& operator +=(const SXBasePoint& PointObj);
	SXBasePoint& operator -=(const SXBasePoint& PointObj);
	SXBasePoint operator +(const SXBasePoint& PointObj);
	SXBasePoint operator -(const SXBasePoint& PointObj);
	bool operator ==(const SXBasePoint& PointObj);
	bool operator !=(const SXBasePoint& PointObj);
	vector<float> m_PointList;
};

class SXPoint2D:public SXBasePoint
{
public:
	SXPoint2D():SXBasePoint(2),x(m_PointList[0]),y(m_PointList[1]){}
	SXPoint2D(float fx,float fy):SXBasePoint(2),x(m_PointList[0]),y(m_PointList[1])
	{
		x=fx;
		y=fy;
	}
	SXPoint2D(const SXBasePoint& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]){}
	SXPoint2D(const SXPoint2D& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]){}
	SXPoint2D& operator =(const SXBasePoint &PointObj)
	{
		x=PointObj.m_PointList[0];
		y=PointObj.m_PointList[1];
		return *this;
	}
	float &x,&y;
};

class SXPoint3D:public SXBasePoint
{
public:
	SXPoint3D():SXBasePoint(3),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]){}
	SXPoint3D(float fx,float fy,float fz):SXBasePoint(3),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2])
	{
		x=fx;
		y=fy;
		z=fz;
	}
	SXPoint3D(const SXBasePoint& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]){}
	SXPoint3D(const SXPoint3D& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]){}
	SXPoint3D& operator =(const SXBasePoint &PointObj)
	{
		x=PointObj.m_PointList[0];
		y=PointObj.m_PointList[1];
		z=PointObj.m_PointList[2];
		return *this;
	}
	float &x,&y,&z;
};

class SXPoint4D:public SXBasePoint
{
public:
	SXPoint4D():SXBasePoint(4),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]),w(m_PointList[3]){}
	SXPoint4D(float fx,float fy,float fz,float fw):SXBasePoint(4),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]),w(m_PointList[3])
	{
		x=fx;
		y=fy;
		z=fz;
		w=fw;
	}
	SXPoint4D(const SXBasePoint& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]),w(m_PointList[3]){}
	SXPoint4D(const SXPoint4D& PointObj):SXBasePoint(PointObj),x(m_PointList[0]),y(m_PointList[1]),z(m_PointList[2]),w(m_PointList[3]){}
	SXPoint4D& operator =(const SXBasePoint &PointObj)
	{
		x=PointObj.m_PointList[0];
		y=PointObj.m_PointList[1];
		z=PointObj.m_PointList[2];
		w=PointObj.m_PointList[3];
		return *this;
	}
	float &x,&y,&z,&w;
};
#endif