// MathLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MathLib.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SXPoint3D p,p1;
	p.x=2.3;
	p.y=3.1;
	p.z=2;
	p1.x=1.1;
	p1.y=2.6;
	p1.z=5;
	SXPoint3D p2=p+p1+10;
	cout<<p2.x<<"  "<<p2.y<<" "<<(p1==p2)<<endl;
	return 0;
}

