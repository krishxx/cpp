#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
	int **data;
	int rows;
	int cols;
	public:
		Matrix();
		void print_matrix();
		void transpose();
		void spiral_rotate();
		void outer_rotate();
		void anti_clock_rotate();
		void print_helical();
		//void k-rotate();
		~Matrix();
};

Matrix::Matrix()
{
	int k=1;
	std::cout<<"enter no.of rows/cols no: ";
	cin>>rows;
	std::cout<<"enter no.of cols ";
	cin>>cols;
	data = new int*[rows];
        for(int i = 0; i < rows; ++i)
                data[i] = new int[cols];

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			data[i][j]=k++;
		}
	}
}

void Matrix::transpose()
{
	int i=0,j=0,temp=0;
        for(i=0;i<rows;i++)
                for(j=i+1;j<cols;j++)
                {
                        temp=data[i][j];
                        data[i][j]=data[j][i];
                        data[j][i]=temp;
                }	
}

void Matrix::spiral_rotate()
{
	int i=0,curr=0,next=0;
	int sr=0,sc=0,er=rows-1,ec=cols-1;
	curr=data[0][0];
	while((sr<er) || (sc<ec))
	{
		for(i=sc;i<=ec;i++)
		{
			next = data[sr][i];
			data[sr][i]=curr;
			curr = next;
		}
		sr++;
		for(i=sr;i<=er;i++)
		{
			next = data[i][ec];
			data[i][ec]=curr;
			curr = next;
		}
		ec--;
		for(i=ec;i>=sc;i--)
		{
			next = data[er][i];
			data[er][i]=curr;
			curr = next;
		}
		er--;
		for(i=er;i>=sr;i--)
		{
			next = data[i][sc];
			data[i][sc]=curr;
			curr = next;
		}
		sc++;
	}
	data[0][0]=curr;
}

void Matrix::outer_rotate()
{
	int i=0, curr=0, next=0;
	int sr=0, er=rows-1, sc=0, ec=cols-1;
	
	while(sc<ec || sr<er)
	{		
		curr=data[sr+1][sc];
		
		for(i=sc;i<=ec;i++)
		{
			next=data[sr][i];
			data[sr][i]=curr;
			curr=next;	
		}
		sr++;
		for(i=sr;i<=er;i++)
		{
			next=data[i][ec];
			data[i][ec]=curr;
			curr=next;
		}
		ec--;
		for(i=ec;i>=sc;i--)
		{
			next=data[er][i];
			data[er][i]=curr;
			curr=next;
		}
		er--;
		for(i=er;i>=sr;i--)
		{
			next=data[i][sc];
			data[i][sc]=curr;
			curr=next;
		}
		sc++;		
	}

}

void Matrix::anti_clock_rotate()
{
	int i=0, curr=0, next=0;
	int sr=0, er=rows-1, sc=0, ec=cols-1;
	
	while(sc<ec || sr<er)
	{		
		curr=data[sr+1][ec];
		for(i=ec;i>=sc;i--)
		{
			next=data[sr][i];
			data[sr][i]=curr;
			curr=next;
		}
		sr++;
		for(i=sr;i<=er;i++)
		{
			next=data[i][sc];
			data[i][sc]=curr;
			curr=next;
		}
		sc++;
		for(i=sc;i<=ec;i++)
		{
			next=data[er][i];
			data[er][i]=curr;
			curr=next;
		}
		er--;
		for(i=er;i>=sr;i--)
		{
			next=data[i][ec];
			data[i][ec]=curr;
			curr=next;
		}
		ec--;
	}		
}

/*
void Matrix::anti_clockwise_rotate()
{
	int i=0,curr=0,next=0;
	int sr=0,sc=0,er=rows-1,ec=cols-1;
	curr=data[sr][ec];
	while((sr<er) || (sc<ec))
	{
		for(i=ec;i>=sc;i--)
		{
			next = data[sr][i];
			data[sr][i]=curr;
			curr = next;
		}
		sr++;
		for(i=sr;i<=er;i++)
		{
			next = data[i][ec];
			data[i][ec]=curr;
			curr = next;
		}
		sc++;

		for(i=sc;i<=ec;i++)
		{
			next = data[er][i];
			data[er][i]=curr;
			curr = next;
		}
		er--;
		for(i=er;i>=sr;i--)
		{
			next = data[i][ec];
			data[i][ec]=curr;
			curr = next;
		}
		ec--;
	}
	data[sr][ec]=curr;
}*/

Matrix::~Matrix()
{
	delete [] data;
}

void Matrix::print_matrix()//(int **mat, int m, int n)
{
	for (int i=0; i<rows;i++)
        {
             for(int j=0; j<cols; j++)
             {
             	std::cout<<setw(2)<<data[i][j]<<" ";
             }
             cout<<endl;
        }
}

void Matrix::print_helical()
{
	int i=0, sr=0,sc=0,er=rows-1,ec=cols-1;
	cout<<"Printing Spirally/Helically"<<endl;
        while(sr<er || sc<ec)
        {
                for(i=sc; i<=ec; i++)
                {
                        cout<<data[sr][i]<<",";
                }
                sr++;
                for(i=sr; i<=er; i++)
                {
                        cout<<data[i][ec]<<",";
                }
                ec--;
                for(i=ec; i>=sc; i--)
                {
                        cout<<data[er][i]<<",";
                }
                er--;
                for(i=er; i>=sr; i--)
                {
                        cout<<data[i][sc]<<",";
                }
                sc++;
        }
        cout<<'\b'<<'\b'<<endl;
}


int main()
{
	Matrix m1;
	cout<<"Original Matrix "<<endl;
	m1.print_matrix();
//	m1.spiral_rotate();
//	cout<<"After Rotate "<<endl;
//	m1.print_matrix();
//	m1.transpose();
//	cout<<"After Transpose "<<endl;
//	m1.print_matrix();
//	m1.print_helical();

	cout<<"Outer Layer rotation"<<endl;
	m1.outer_rotate();
	m1.print_matrix();
	cout<<"Anti Clock outer Rotation"<<endl;
	m1.anti_clock_rotate();
	m1.print_matrix();

	return 0;
}

/*
Inplace (Fixed space) M x N size matrix transpose | Updated
Rotate Matrix Elements
Rotate a Matrix by 180 degree
Rotate the matrix right by K times
Rotate a matrix by 90 degree without using any extra space | Set 2
Rotate each ring of matrix anticlockwise by K elements
Rotate a matrix by 90 degree in clockwise direction without using any extra space
Maximum size square sub-matrix with all 1s
Maximum and Minimum in a square matrix.
How to access elements of a Square Matrix
Check given matrix is magic square or not
Print maximum sum square sub-matrix of given size
Given an n x n square matrix, find sum of all sub-squares of size k x k
Product of middle row and column in an odd square matrix
Sum of both diagonals of a spiral odd-order square matrix
*/
