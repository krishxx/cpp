#include <iostream>
using namespace std;

int missingNo(int a[], int n)
{
	int xr=a[i];
	for(int i=2;i<=n; i++)
		xr=xr^i;
	cout<<endl<<xr<<endl;
	for(int i=0;i<n;i++)
		xr=xr^a[i];

	return xr;
}

int main()
{
	int arr[]={1,2,3,5};
	cout<<"missing no is "<<missingNo(arr, 4)<<endl;

	return 0;
}
