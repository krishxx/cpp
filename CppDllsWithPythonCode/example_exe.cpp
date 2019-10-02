#include <stdio.h>
#include "example_dll.h"

int main(void)
{
        hello("World");
		testpycode("are you in?");
        printf("%d\n", Double(333));
        CppFunc();

        MyClass a;
        a.func();

        return 0;
}