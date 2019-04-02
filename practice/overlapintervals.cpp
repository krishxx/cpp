#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
	int start, end;
}Interval;

bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n)
{
	if(n<=0)
		return;
	//create ean empty stack
	stack<Interval> s;
	sort(arr, arr+n, compareInterval);
	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		Interval top=s.top();
		if(top.end<arr[i].start)
			s.push(arr[i]);
		else if(top.end<arr[i].end)
		{
			top.end = arr[i].end;
			s.top();
			s.push(top);
		}
	}
	cout<< "\n The merged intervals are: ";
	while(!s.empty())
	{
		Interval t=s.top();
		cout<< "[" << t.start<<","<<t.end<<"]";
		s.pop();
	}
	cout<<endl;
	return;	
}

int main()
{
	Interval arr[]={{6,8},{1,9},{2,4},{4,7},{20,30}};
	int n= sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr,n);
	return 0;
}
