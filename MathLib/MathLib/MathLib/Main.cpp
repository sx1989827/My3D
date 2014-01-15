// MathLib.cpp : 定义控制台应用程序的入口点。
//
#include "MathLib.h"

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, const char * argv[])
#endif
{
    SXMatrix4 m;
    SXMatrix4Translation(&m,1.2, 3.3, -0.2);
    SXMatrix4TranslationInverse(&m, &m);
    cout<<m<<endl;
    return 0;
}

