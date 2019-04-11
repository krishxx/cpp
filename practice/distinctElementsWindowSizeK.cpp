#include <iostream>
#include <iomanip>
using namespace std;
void countDistinct1(int a[], int n, int k)
{
	int count=0;;
	for(int i=0; i<n-k+1; i++)
	{
		count=k;
		cout<<"from window {";
		for(int j=i; j<i+k; j++)
		{
			for(int m=j+1;m<i+k;m++)
			{
				if(a[j]==a[m])
					count--;

			}
			cout<<a[j]<<",";
		}
		cout<<"\b}:"<<count<<endl;
	}
}//O(nk2)

void countDistinct2(int a[], int n, int k)
{
	map<int, int> hm;
	int count=0;
	for(int i=0;i<k;i++)
	{
		if(hm[a[i]]==0)
			count++;
		hm[a[i]]+=1;
	}
	cout<<count<<endl;
	
	for(int i=k; i<n; i++)
	{
		if(hm[arr[i-k]] == 1)
		{
			count--;
		}
		hm[arr[i-k]] -= 1;
	}	
}

int main()
{
	int arr[]={1,1,2,3,4,4,2};
	countDistinct1(arr, 7, 3);
	return 0;
}
