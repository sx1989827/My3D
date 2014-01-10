// MathLib.cpp : 定义控制台应用程序的入口点。
//
#ifdef _WIN32
#include "stdafx.h"
#endif
#include "MathLib.h"

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char * argv[])
#endif
{
	SXPoint2D p,p1;
	p.x=2.3;
	p.y=3.1;
	p1.x=1.1;
	p1.y=2.6;
	SXPoint2D p2=p+p1;
	cout<<p2.x<<"  "<<p2.y<<" "<<(p1==p2)<<endl;
	return 0;
}

