#include <iostream>
using namespace std;

int numberofpaths(int m, int n)
{
	if(m==1 | n==1)
		return 1;
	return numberofpaths(m-1,n)+numberofpaths(m,n-1);
}

int main()
{
	cout<<"no of paths: "<<numberofpaths(3,4)<<endl;
	return 0;
}
