#include <stdio.h>
#include "example_dll.h"
#include "Python.h"

__stdcall void hello(const char *s)
{
        printf("Hello %s\n", s);
}

__stdcall void testpycode(const char *s)
{
	Py_Initialize();
        printf("Python world: %s\n", s);
	Py_Finalize();
}
int Double(int x)
{
        return 2 * x;
}
void CppFunc(void)
{
        puts("CppFunc");
}
void MyClass::func(void)
{
        puts("MyClass.func()");
}