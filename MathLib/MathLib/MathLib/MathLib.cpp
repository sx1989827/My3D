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

ostream& operator <<(ostream& o,const SXBasePoint& obj)
{
	for(int i=0;i<obj.m_PointList.size();i++)
	{
		o<<obj.m_PointList[i]<<" ";
	}
	return o;
}

istream& operator >>(istream& in, SXPoint2D& obj)
{
	for(int i=0;i<2;i++)
	{
        float data;
		in>>data;
        obj.m_PointList[i]=data;
	}
	return in;
}

istream& operator >>(istream& in,SXPoint3D& obj)
{
	for(int i=0;i<3;i++)
	{
        float data;
		in>>data;
        obj.m_PointList[i]=data;
	}
	return in;
}

istream& operator >>(istream& in, SXPoint4D& obj)
{
	for(int i=0;i<4;i++)
	{
        float data;
		in>>data;
        obj.m_PointList[i]=data;
	}
	return in;
}
///////////////////////////////////////////////////////////////////////////////////////

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

ostream& operator <<(ostream& o,const SXMatrix3& obj)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<obj.m_Data[row][col]<<" ";
		}
		if(row<2)
		{
			cout<<endl;
		}
	}
	return o;
}

istream& operator >>(istream& in, SXMatrix3& obj)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
            float data;
			in>>data;
            obj.m_Data[row][col]=data;
		}
	}
	return in;
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

ostream& operator <<(ostream& o,const SXMatrix4& obj)
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
			cout<<obj.m_Data[row][col]<<" ";
		}
		if(row<3)
		{
			cout<<endl;
		}
	}
	return o;
}

istream& operator >>(istream& in, SXMatrix4& obj)
{
	for(int row=0;row<4;row++)
	{
		for(int col=0;col<4;col++)
		{
            float data;
			in>>data;
            obj.m_Data[row][col]=data;
		}
	}
	return in;
}

float _determinant(SXMatrix3* pIn)
{
	return pIn->_11*(pIn->_22*pIn->_33-pIn->_23*pIn->_32)+pIn->_12*(pIn->_23*pIn->_31-pIn->_21*pIn->_33)+pIn->_13*(pIn->_21*pIn->_32-pIn->_22*pIn->_31);
}


SXMatrix3* SXMatrix3Transpose( SXMatrix3 *pOut,SXMatrix3* pIn )
{
    SXMatrix3 InputMat=*pIn;
    pIn=&InputMat;
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			pOut->m_Data[row][col]=pIn->m_Data[col][row];
		}
	}
	return pOut;
}

 SXMatrix3* SXMatrix3Inverse( SXMatrix3 *pOut,SXMatrix3* pIn )
 {
     SXMatrix3 InputMat=*pIn;
     pIn=&InputMat;
	float det=_determinant(pIn);
	assert(fabs(det)>0.000001);
	float OverDet=1/det;
	pOut->_11=(pIn->_22*pIn->_33-pIn->_23*pIn->_32)*OverDet;
	pOut->_12=(pIn->_13*pIn->_32-pIn->_12*pIn->_33)*OverDet;
	pOut->_13=(pIn->_12*pIn->_23-pIn->_13*pIn->_22)*OverDet;
	pOut->_21=(pIn->_23*pIn->_31-pIn->_21*pIn->_33)*OverDet;
	pOut->_22=(pIn->_11*pIn->_33-pIn->_13*pIn->_31)*OverDet;
	pOut->_23=(pIn->_13*pIn->_21-pIn->_11*pIn->_23)*OverDet;
	pOut->_31=(pIn->_21*pIn->_32-pIn->_22*pIn->_31)*OverDet;
	pOut->_32=(pIn->_12*pIn->_31-pIn->_11*pIn->_32)*OverDet;
	pOut->_33=(pIn->_11*pIn->_22-pIn->_12*pIn->_21)*OverDet;
	return pOut;
 }

SXPoint2D* SXPos2TransformCoord( SXPoint2D* pOut,SXPoint2D* pIn,SXMatrix3 *pM )
{
		SXPoint3D p(pIn->x,pIn->y,1);
		pOut->x=p.x*pM->_11+p.y*pM->_21+p.z*pM->_31;
		pOut->y=p.x*pM->_12+p.y*pM->_22+p.z*pM->_32;
		return pOut;
}

SXPoint2D* SXPos2TransformNormal( SXPoint2D* pOut,SXPoint2D* pIn,SXMatrix3 *pM )
{
	SXPoint3D p(pIn->x,pIn->y,0);
	pOut->x=p.x*pM->_11+p.y*pM->_21+p.z*pM->_31;
	pOut->y=p.x*pM->_12+p.y*pM->_22+p.z*pM->_32;
	return pOut;
}

 SXMatrix4* SXMatrix4Transpose( SXMatrix4 *pOut,SXMatrix4* pIn )
 {
     SXMatrix4 InputMat=*pIn;
     pIn=&InputMat;
	 for(int row=0;row<4;row++)
	 {
		 for(int col=0;col<4;col++)
		 {
			 pOut->m_Data[row][col]=pIn->m_Data[col][row];
		 }
	 }
	 return pOut;
 }
 
SXMatrix4* SXMatrix4Inverse( SXMatrix4 *pOut,SXMatrix4* pIn )
{
    SXMatrix4 InputMat=*pIn;
    pIn=&InputMat;
	float s0 = pIn->_11 * pIn->_22 - pIn->_21 * pIn->_12;
	float s1 = pIn->_11 * pIn->_23 - pIn->_21 * pIn->_13;
	float s2 = pIn->_11 * pIn->_24 - pIn->_21 * pIn->_14;
	float s3 = pIn->_12 * pIn->_23 - pIn->_22 * pIn->_13;
	float s4 = pIn->_12 * pIn->_24 - pIn->_22 * pIn->_14;
	float s5 = pIn->_13 * pIn->_24 - pIn->_23 * pIn->_14;

	float c5 = pIn->_33 * pIn->_44 - pIn->_43 * pIn->_34;
	float c4 = pIn->_32 * pIn->_44 - pIn->_42 * pIn->_34;
	float c3 = pIn->_32 * pIn->_43 - pIn->_42 * pIn->_33;
	float c2 = pIn->_31 * pIn->_44 - pIn->_41 * pIn->_34;
	float c1 = pIn->_31 * pIn->_43 - pIn->_41 * pIn->_33;
	float c0 = pIn->_31 * pIn->_42 - pIn->_41 * pIn->_32;

	float det=s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
	assert(fabs(det)>0.000001);
	float invdet = 1.0 /det;

	pOut->_11 = ( pIn->_22 * c5 - pIn->_23 * c4 + pIn->_24 * c3) * invdet;
	pOut->_12 = (-pIn->_12 * c5 + pIn->_13 * c4 - pIn->_14 * c3) * invdet;
	pOut->_13 = ( pIn->_42 * s5 - pIn->_43 * s4 + pIn->_44 * s3) * invdet;
	pOut->_14 = (-pIn->_32 * s5 + pIn->_33 * s4 - pIn->_34 * s3) * invdet;

	pOut->_21 = (-pIn->_21 * c5 + pIn->_23 * c2 - pIn->_24 * c1) * invdet;
	pOut->_22 = ( pIn->_11 * c5 - pIn->_13 * c2 + pIn->_14 * c1) * invdet;
	pOut->_23= (-pIn->_41 * s5 + pIn->_43 * s2 - pIn->_44 * s1) * invdet;
	pOut->_24 = ( pIn->_31 * s5 - pIn->_33 * s2 + pIn->_34 * s1) * invdet;

	pOut->_31 = ( pIn->_21 * c4 - pIn->_22 * c2 + pIn->_24 * c0) * invdet;
	pOut->_32 = (-pIn->_11 * c4 + pIn->_12 * c2 - pIn->_14 * c0) * invdet;
	pOut->_33 = ( pIn->_41 * s4 - pIn->_42 * s2 + pIn->_44 * s0) * invdet;
	pOut->_34 = (-pIn->_31 * s4 + pIn->_32 * s2 - pIn->_34 * s0) * invdet;

	pOut->_41 = (-pIn->_21 * c3 + pIn->_22 * c1 - pIn->_23 * c0) * invdet;
	pOut->_42 = ( pIn->_11 * c3 - pIn->_12 * c1 + pIn->_13 * c0) * invdet;
	pOut->_43 = (-pIn->_41 * s3 + pIn->_42 * s1 - pIn->_43 * s0) * invdet;
	pOut->_44 = ( pIn->_31 * s3 - pIn->_32 * s1 + pIn->_33 * s0) * invdet;
	return pOut;
}
 
SXPoint3D* SXPos3TransformCoord( SXPoint3D* pOut,SXPoint3D* pIn,SXMatrix4 *pM )
{
	SXPoint4D p(pIn->x,pIn->y,pIn->z,1);
	pOut->x=p.x*pM->_11+p.y*pM->_21+p.z*pM->_31+p.w*pM->_41;
	pOut->y=p.x*pM->_12+p.y*pM->_22+p.z*pM->_32+p.w*pM->_42;
	pOut->z=p.x*pM->_13+p.y*pM->_23+p.z*pM->_33+p.w*pM->_43;
	return pOut;
}

SXPoint3D* SXPos3TransformNormal( SXPoint3D* pOut,SXPoint3D* pIn,SXMatrix4 *pM )
{
	SXPoint4D p(pIn->x,pIn->y,pIn->z,0);
	pOut->x=p.x*pM->_11+p.y*pM->_21+p.z*pM->_31+p.w*pM->_41;
	pOut->y=p.x*pM->_12+p.y*pM->_22+p.z*pM->_32+p.w*pM->_42;
	pOut->z=p.x*pM->_13+p.y*pM->_23+p.z*pM->_33+p.w*pM->_43;
	return pOut;
}
