#include <iostream>
#include <iomanip>
#include <map>

using namespace std;
int findRepeatNo(int a[], int n)
{
	std::map<int, int> hm;
	
	for(int i=0;i<n; i++)
	{
		hm[a[i]]+=1;
		if(hm[a[i]]>1)
		{
			cout<<"repeated no. is "<<a[i]<<endl;
			return a[i];
		}			
	}
	return 0;
}

//when no.s from 1 to n -> complexity O(n) and space complexity O(1)
int findRepeatNo2(int a[], int n)
{
	int *ca = new int(n);//count array
	for(int i=0;i<n; i++)
		ca[i]=0;
	for(int i=0; i<n; i++)
	{
		ca[a[i]]+=1;
		if(ca[a[i]]>1)
		{
			cout<<"repeated no is "<<a[i]<<endl;
			return a[i];
		}
	}
	delete [] ca;
	return 0;	
}

int main()
{
	int arr[]={1,3,2,3,2,4};
	findRepeatNo(arr,6);
	int arr2[]={1,2,3,4,5,5};
	findRepeatNo2(arr2,6);
	return 0;
}
