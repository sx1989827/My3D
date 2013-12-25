#include "MathLib.h"

SXBasePoint::SXBasePoint( int iPointCount )
{
	m_PointList.assign(iPointCount,0.0f);
}

SXBasePoint::SXBasePoint( const SXBasePoint& PointObj )
{
	m_PointList=PointObj.m_PointList;
}

SXBasePoint SXBasePoint::operator+( float fValue)
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]+fValue;
	}
	return PointTemp;
}

SXBasePoint operator +(float fValue,const SXBasePoint& PointObj)
{
	SXBasePoint PointTemp(PointObj.m_PointList.size());
	for(int i=0;i<PointObj.m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=PointObj.m_PointList[i]+fValue;
	}
	return PointTemp;
}

SXPoint2D& SXPoint2D::operator=( const SXBasePoint &PointObj )
{
	x=PointObj.m_PointList[0];
	y=PointObj.m_PointList[1];
	return *this;
}
