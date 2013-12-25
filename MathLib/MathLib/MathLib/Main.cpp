// MathLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MathLib.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SXPoint2D p;
	p.x=2.3;
	p.y=3.1;
	SXPoint2D p1=5.0f+p;
	cout<<p1.x<<"  "<<p1.y<<endl;
	return 0;
}

