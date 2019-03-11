#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//int matrix[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}


void transpose_matrix(int **a, int m, int n);
void transpose_matrix(int **mat, int m, int n)
{
	int i=0,j=0,temp=0;
	for(i=0;i<m;i++)
		for(j=i+1;j<n;j++)
		{
			temp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=temp;
		}
}

void print_matrix(int **mat, int m, int n)
{
	for (int i=0; i<m;i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cout<<setw(2)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}				
}

void swap(int *a, int *b)
{
	int temp=0;
	temp = *a;
	*a=*b;
	*b=temp;
}

void rotate_matrix(int **mat, int m, int n)
{
	int sc=0,sr=0,er=m,ec=n,i=0,j=0, holdVal=0, val=0;
	while(sc<ec && sr<er)
	{
		val=mat[sr+1][sc];
		//holdVal=mat[sr][i];
		for(i=sc;i<ec;i++)
		{
			holdVal=mat[sr][i+1];
			mat[sr][i]=val;			
		}
			
	}
}
int main()
{	
	int i=0,j=0;
	int** a = new int*[5];
	for(i = 0; i < 5; ++i)
    		a[i] = new int[5];

	int k=1;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			a[i][j] = k++;
		}
	}

	//transpose_matrix(a,5,5);
	int temp1=0, temp2=0;
	cout<<"BEFORE-->"<<endl;
	print_matrix(a,5,5);

        for(i=0; i<5; i++)
	{
                for(j=i+1;j<5;j++)
                {
			//a[i][j]=99;
			//temp1=a[i][j];
			//temp2=a[j][i];
			
			swap(&a[i][j], &a[j][i]);			
			/*cout<<"before:"<<a[i][j]<<" "<<a[j][i]<<endl;
                        temp=a[i][j];
                        a[i][j]=a[j][i];
                        a[j][i]=temp;
			//cout<<"after:"<<a[i][j]<<" "<<a[j][i]<<endl;*/
                }
	}

	cout<<"AFTER-->"<<endl;
	print_matrix(a,5,5);
	delete [] a;	
	return 0;
}
