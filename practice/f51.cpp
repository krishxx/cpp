#include <iostream>
#include <stdio.h>

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

using namespace std;
static int cnt=0;
template <typename T>
T foo2(T t)
{
	cnt++;
	return t*2;
}

int foo(int val)
{
	static int tmp=1;
	if(val>=5) return val;
	val+=tmp;
	tmp++;
	return foo(val);
}

int main()
{
	cout<<foo(1);
	cout<<endl;
	char c[]="F5NETWORKS";
	char *ptr=c;
	printf("%s\n",ptr+ptr[0]-ptr[3]);
	cout<<endl;

	char c2=0;
	long i=1;
	short j=2;

	c2=foo2(c2);
	i=foo2(i);
	j=foo2(j);
	cout<<"instas "<<cnt<<endl;

	//std::string s="Hello";
	//s=foo2(s);
	//
	
	char* input=new char[100];
	input[0]='h';

	//read(STDIN_FILENO, input, 100);
	std::string s;
	s.reserve(100);
	s=input;
	delete[] input;
	cout<<s;

	//foo3(std::shared_ptr<Widget>(new Widget{}), bar());`
	return 0;
}

/*The evaluation of the arguments are not sequenced with respect to one another.That is, the allocation is sequenced before the shared_ptr constructor, but neither of those is sequenced with respect to the other argument and there is no guarantee that nothing happens inbetween the allocation and the constructor call.
 */
