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


SXMatrix3 SXMatrix3::operator+( const SXMatrix3& obj )
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]+obj.m_Data[row][col];
		}
	}
	return Mat;
}

SXMatrix3 SXMatrix3::operator-( const SXMatrix3& obj )
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]-obj.m_Data[row][col];
		}
	}
	return Mat;
}

SXMatrix3 SXMatrix3::operator*( float fVal )
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]*fVal;
		}
	}
	return Mat;
}

SXMatrix3 SXMatrix3::operator*( const SXMatrix3& obj )
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][0]*obj.m_Data[0][col]+m_Data[row][1]*obj.m_Data[1][col]+m_Data[row][2]*obj.m_Data[2][col];
		}
	}
	return Mat;
}

SXMatrix3::SXMatrix3()
{
	Identity();
}

SXMatrix3& SXMatrix3::operator+=( const SXMatrix3& obj )
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			m_Data[row][col]+=obj.m_Data[row][col];
		}
	}
	return *this;
}

SXMatrix3& SXMatrix3::operator-=( const SXMatrix3& obj )
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			m_Data[row][col]-=obj.m_Data[row][col];
		}
	}
	return *this;
}

SXMatrix3& SXMatrix3::operator*=( float fVal )
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			m_Data[row][col]*=fVal;
		}
	}
	return *this;
}

SXMatrix3& SXMatrix3::operator*=( const SXMatrix3& obj )
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][0]*obj.m_Data[0][col]+m_Data[row][1]*obj.m_Data[1][col]+m_Data[row][2]*obj.m_Data[2][col];
		}
	}
	memcpy(this,&Mat,sizeof(float)*9);
	return *this;
}

SXMatrix3& SXMatrix3::Identity()
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			if(row==col)
			{
				m_Data[row][col]=1;
			}
			else
			{
				m_Data[row][col]=0;
			}			
		}
	}
	return *this;
}

SXMatrix3 operator *(float fVal,const SXMatrix3& obj)
{
	SXMatrix3 Mat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			Mat.m_Data[row][col]=obj.m_Data[row][col]*fVal;
		}
	}
	return Mat;
}

///////////////////////////////////////////////////////////////////////////////////////

SXMatrix4 SXMatrix4::operator+( const SXMatrix4& obj )
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]+obj.m_Data[row][col];
		}
	}
	return Mat;
}

SXMatrix4 SXMatrix4::operator-( const SXMatrix4& obj )
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]-obj.m_Data[row][col];
		}
	}
	return Mat;
}

SXMatrix4 SXMatrix4::operator*( float fVal )
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][col]*fVal;
		}
	}
	return Mat;
}

SXMatrix4 SXMatrix4::operator*( const SXMatrix4& obj )
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][0]*obj.m_Data[0][col]+m_Data[row][1]*obj.m_Data[1][col]+m_Data[row][2]*obj.m_Data[2][col]+m_Data[row][3]*obj.m_Data[3][col];
		}
	}
	return Mat;
}

SXMatrix4::SXMatrix4()
{
	Identity();
}

SXMatrix4& SXMatrix4::operator+=( const SXMatrix4& obj )
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			m_Data[row][col]+=obj.m_Data[row][col];
		}
	}
	return *this;
}

SXMatrix4& SXMatrix4::operator-=( const SXMatrix4& obj )
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			m_Data[row][col]-=obj.m_Data[row][col];
		}
	}
	return *this;
}

SXMatrix4& SXMatrix4::operator*=( float fVal )
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			m_Data[row][col]*=fVal;
		}
	}
	return *this;
}

SXMatrix4& SXMatrix4::operator*=( const SXMatrix4& obj )
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=m_Data[row][0]*obj.m_Data[0][col]+m_Data[row][1]*obj.m_Data[1][col]+m_Data[row][2]*obj.m_Data[2][col]+m_Data[row][3]*obj.m_Data[3][col];
		}
	}
	memcpy(this,&Mat,sizeof(float)*16);
	return *this;
}

SXMatrix4& SXMatrix4::Identity()
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			if(row==col)
			{
				m_Data[row][col]=1;
			}
			else
			{
				m_Data[row][col]=0;
			}			
		}
	}
	return *this;
}

SXMatrix4 operator *(float fVal,const SXMatrix4& obj)
{
	SXMatrix4 Mat;
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			Mat.m_Data[row][col]=obj.m_Data[row][col]*fVal;
		}
	}
	return Mat;
}