#include <iostream>
#include <iomanip>
using namespace std;

typedef struct
{
	int min;
	int max;
}minmaxpair;


minmaxpair getMinMaxPair(int a[], int n)
{
	minmaxpair p;
	p.min=a[0];
	p.max=a[0];
	for(int i=1;i<n;i++)
	{
		if(p.min>a[i])
			p.min=a[i];
		if(p.max<a[i])
			p.max=a[i];
	}
	cout<<"min-max pair is :{"<<p.min<<","<<p.max<<"}\n";
	return p;
}

int main()
{
	int arr[]={10,9,1,3,7,2,5};
	minmaxpair q;
	q = getMinMaxPair(arr,7);
	cout<<"min-max pair is :{"<<q.min<<","<<q.max<<"}\n";
	return 0;
}
