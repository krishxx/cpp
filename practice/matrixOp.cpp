#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

typedef struct
{
	int x;
	int y;
	int v;
}pt_t;

int countClustersInMatrix(int **arr, int rows, int cols)
{
	pt_t pt[rows][cols]={0,};
	int clusterCnt=0;
	std::stack<pt_t> st;
	
	for(int i=0; i<rows; i++)
	for(int j=0; j<cols; j++)
	{
		pt[i][j].x=i;
		pt[i][j].y=j;
		pt[i][j].v=0;
	}
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(pt[i][j].v==0 && arr[i][j]==1)
			{
				st.push(pt[i][j]);
				int k=i,l=j;
				pt_t item, item1, item2;
				while(!st.empty())
				{
					item = st.top();					
					k=item.x;
					l=item.y;
					pt[k][l].v=1;
					st.pop();
					if((k+1<rows)&&(pt[k+1][l].v==0)&&(arr[k+1][l]==1))
					{
						item1=pt[k+1][l];
						st.push(item1);						
					}
					if(l+1<cols && pt[k][l+1].v==0 && (arr[k][l+1]==1))
					{
						item2=pt[k][l+1];
						st.push(item2);
					}
					//need to add left & and top directions also
				}
				clusterCnt++;
			}
		}
	}
	return clusterCnt;
}


int main(int argc, char **argv)
{
	//printf("hello world\n");
	std::cout<<" Hello Matrix World\n";
	
	int **a;
	a = new int *[4];
	for(int i = 0; i<4; i++)
		a[i] = new int[4];
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			a[i][j]=(i%2==0)||(j%3==0);			
		}
	}
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			std::cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"No.of Clusters ";
	cout<<countClustersInMatrix(a, 4, 4)<<endl;
	return 0;
}
