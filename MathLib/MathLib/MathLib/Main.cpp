// MathLib.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "MathLib.h"

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char * argv[])
#endif
{
	SXPoint3D p(1,2,3);
    SXMatrix4 m;
    cin>>m;
    SXPos3TransformCoord(&p, &p, &m);
    cout<<p<<endl;
	return 0;
}

