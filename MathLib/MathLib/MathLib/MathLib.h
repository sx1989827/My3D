#ifndef SXMATHLIB
#define SXMATHLIB
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#ifdef _WIN32
#include <tchar.h>
#endif
using namespace std;
#define PRECISION 0.000001
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
	float Length();
	SXBasePoint& Normalize();
	float Dot(const SXBasePoint& PointObj);
	SXBasePoint Cross(const SXBasePoint& PointObj);
	friend ostream& operator <<(ostream& o,const SXBasePoint& obj);
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
	friend istream& operator >>(istream& in, SXPoint2D& obj);
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
	friend istream& operator >>(istream& in, SXPoint3D& obj);
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
	friend istream& operator >>(istream& in, SXPoint4D& obj);
	float &x,&y,&z,&w;
};

class SXMatrix3
{
public:
	union
	{
		float m_Data[3][3];
		struct
		{
			float _11,_12,_13;
			float _21,_22,_23;
			float _31,_32,_33;
		};
	};
	SXMatrix3();
	SXMatrix3 operator + (const SXMatrix3& obj);
	SXMatrix3 operator - (const SXMatrix3& obj);
	SXMatrix3 operator * (float fVal);
	SXMatrix3 operator * (const SXMatrix3& obj);
	SXMatrix3& operator += (const SXMatrix3& obj);
	SXMatrix3& operator -= (const SXMatrix3& obj);
	SXMatrix3& operator *= (float fVal);
	SXMatrix3& operator *= (const SXMatrix3& obj);
	friend SXMatrix3 operator *(float fVal,const SXMatrix3& obj);
	friend ostream& operator <<(ostream& o,const SXMatrix3& obj);
	friend istream& operator >>(istream& in, SXMatrix3& obj);
	SXMatrix3& Identity();
};

class SXMatrix4
{
public:
	union
	{
		float m_Data[4][4];
		struct
		{
			float _11,_12,_13,_14;
			float _21,_22,_23,_24;
			float _31,_32,_33,_34;
			float _41,_42,_43,_44;
		};
	};
	SXMatrix4();
	SXMatrix4 operator + (const SXMatrix4& obj);
	SXMatrix4 operator - (const SXMatrix4& obj);
	SXMatrix4 operator * (float fVal);
	SXMatrix4 operator * (const SXMatrix4& obj);
	SXMatrix4& operator += (const SXMatrix4& obj);
	SXMatrix4& operator -= (const SXMatrix4& obj);
	SXMatrix4& operator *= (float fVal);
	SXMatrix4& operator *= (const SXMatrix4& obj);
	friend SXMatrix4 operator *(float fVal,const SXMatrix4& obj);
	friend ostream& operator <<(ostream& o,const SXMatrix4& obj);
	friend istream& operator >>(istream& in, SXMatrix4& obj);
	SXMatrix4& Identity();
};
///////////////////////////////////////////////////////////////////////////////////
bool SXMathFloatIsEqual(float fx,float fy);
SXMatrix3* SXMatrix3Transpose(SXMatrix3 *pOut,SXMatrix3* pIn);
SXMatrix3* SXMatrix3Inverse(SXMatrix3 *pOut,SXMatrix3* pIn);
SXPoint2D* SXPos2TransformCoord(SXPoint2D* pOut,SXPoint2D* pIn,SXMatrix3 *pM);
SXPoint2D* SXPos2TransformNormal(SXPoint2D* pOut,SXPoint2D* pIn,SXMatrix3 *pM);
SXMatrix4* SXMatrix4Transpose(SXMatrix4 *pOut,SXMatrix4* pIn);
SXMatrix4* SXMatrix4Inverse(SXMatrix4 *pOut,SXMatrix4* pIn);
SXPoint3D* SXPos3TransformCoord(SXPoint3D* pOut,SXPoint3D* pIn,SXMatrix4 *pM);
SXPoint3D* SXPos3TransformNormal(SXPoint3D* pOut,SXPoint3D* pIn,SXMatrix4 *pM);
SXMatrix4* SXMatrix4Translation(SXMatrix4* pInOut,float x,float y,float z);
SXMatrix4* SXMatrix4TranslationInverse(SXMatrix4* pOut,SXMatrix4* pIn);
SXMatrix4* SXMatrix4RotationX(SXMatrix4* pInOut,float fAngle);
SXMatrix4* SXMatrix4RotationY(SXMatrix4* pInOut,float fAngle);
SXMatrix4* SXMatrix4RotationZ(SXMatrix4* pInOut,float fAngle);
SXMatrix4* SXMatrix4RotationInverse(SXMatrix4* pOut,SXMatrix4* pIn);
SXMatrix4* SXMatrix4Scaling(SXMatrix4* pInOut,float sx,float sy,float sz);
SXMatrix4* SXMatrix4ScalingInverse(SXMatrix4* pOut,SXMatrix4* pIn);
SXMatrix4* SXMatrix4LookAtLH(SXMatrix4 *pInOut, SXPoint3D* pEye, SXPoint3D* pAt, SXPoint3D* pUp);
#endif













