// MathLib.cpp : 定义控制台应用程序的入口点。
//
#include "MathLib.h"

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char * argv[])
#endif
{
	SXMatrix4 mat1,mat2;
	cin>>mat1;
	SXMatrix4Inverse(&mat2,&mat1);
	cout<<mat2<<endl;
	return 0;
}

