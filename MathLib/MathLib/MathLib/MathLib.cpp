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

SXBasePoint SXBasePoint::operator+( const SXBasePoint& PointObj )
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]+PointObj.m_PointList[i];
	}
	return PointTemp;
}

SXBasePoint SXBasePoint::operator-( float fValue )
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]-fValue;
	}
	return PointTemp;
}

SXBasePoint SXBasePoint::operator*( float fValue )
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]*fValue;
	}
	return PointTemp;
}

SXBasePoint SXBasePoint::operator/( float fValue )
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]/fValue;
	}
	return PointTemp;
}

SXBasePoint& SXBasePoint::operator+=( float fValue )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]+=fValue;
	}
	return *this;
}

SXBasePoint& SXBasePoint::operator+=( const SXBasePoint& PointObj )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]+=PointObj.m_PointList[i];
	}
	return *this;
}

SXBasePoint& SXBasePoint::operator-=( float fValue )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]-=fValue;
	}
	return *this;
}

SXBasePoint& SXBasePoint::operator*=( float fValue )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]*=fValue;
	}
	return *this;
}


SXBasePoint& SXBasePoint::operator/=( float fValue )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]/=fValue;
	}
	return *this;
}


SXBasePoint& SXBasePoint::operator-=( const SXBasePoint& PointObj )
{
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]-=PointObj.m_PointList[i];
	}
	return *this;
}

bool SXBasePoint::operator==( const SXBasePoint& PointObj )
{
	for(int i=0;i<PointObj.m_PointList.size();i++)
	{
		if(!SXMathFloatIsEqual(m_PointList[i],PointObj.m_PointList[i]))
		{
			return false;
		}
	}
	return true;
}

bool SXBasePoint::operator!=( const SXBasePoint& PointObj )
{
	if(operator ==(PointObj))
	{
		return false;
	}
	else
	{
		return true;
	}
}

SXBasePoint SXBasePoint::operator-( const SXBasePoint& PointObj )
{
	SXBasePoint PointTemp(m_PointList.size());
	for(int i=0;i<m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=m_PointList[i]-PointObj.m_PointList[i];
	}
	return PointTemp;
}


SXBasePoint operator /(float fValue,const SXBasePoint& PointObj)
{
	SXBasePoint PointTemp(PointObj.m_PointList.size());
	for(int i=0;i<PointObj.m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=fValue/PointObj.m_PointList[i];
	}
	return PointTemp;
}

SXBasePoint operator *(float fValue,const SXBasePoint& PointObj)
{
	SXBasePoint PointTemp(PointObj.m_PointList.size());
	for(int i=0;i<PointObj.m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=PointObj.m_PointList[i]*fValue;
	}
	return PointTemp;
}

SXBasePoint operator -(float fValue,const SXBasePoint& PointObj)
{
	SXBasePoint PointTemp(PointObj.m_PointList.size());
	for(int i=0;i<PointObj.m_PointList.size();i++)
	{
		PointTemp.m_PointList[i]=fValue-PointObj.m_PointList[i];
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

bool SXMathFloatIsEqual( float fx,float fy )
{
	return fabs(fx-fy)<=PRECISION;
}

