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

float SXBasePoint::Length()
{
	float fSum=0;
	for(int i=0;i<m_PointList.size();i++)
	{
		fSum+=m_PointList[i]*m_PointList[i];
	}
	return sqrtf(fSum);
}

SXBasePoint& SXBasePoint::Normalize()
{
	int iSize=Length();
	for(int i=0;i<m_PointList.size();i++)
	{
		m_PointList[i]/=iSize;
	}
	return *this;
}

float SXBasePoint::Dot( const SXBasePoint& PointObj )
{
	float fDot=0;
	for(int i=0;i<m_PointList.size();i++)
	{
		fDot+=m_PointList[i]*PointObj.m_PointList[i];
	}
	return fDot;
}

SXBasePoint SXBasePoint::Cross( const SXBasePoint& PointObj )
{
	assert(m_PointList.size()==3);
	SXBasePoint PointTemp(3);
	PointTemp.m_PointList[0]=m_PointList[1]*PointObj.m_PointList[2]-PointObj.m_PointList[1]*m_PointList[2];
	PointTemp.m_PointList[1]=m_PointList[2]*PointObj.m_PointList[0]-PointObj.m_PointList[2]*m_PointList[0];
	PointTemp.m_PointList[2]=m_PointList[0]*PointObj.m_PointList[1]-PointObj.m_PointList[0]*m_PointList[1];
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

