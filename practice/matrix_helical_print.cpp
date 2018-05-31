/*
 * Implement a function which prints the matrix elements in helical or spiral order
 *
 * Given Matrix (Input)
 * 11, 12, 13, 14
 * 15, 16, 17, 18
 * 19, 20, 21, 22
 * 23, 24, 25, 26
 *
 * Expected output
 *
 * 11, 12, 13, 14, 18, 22, 26, 25, 24, 23, 19, 15, 16, 17, 21, 20
 * 
 */

#include <iostream>
using namespace std;

#define N 4
void print_helical_matrix(int arr[4][4], int r, int c)
{
	int i=0, sr=0, sc=0, er=r-1, ec=c-1;
	while(sr<er || sc<ec)
	{
		for(i=sc; i<=ec; i++)
		{
			cout<<arr[sr][i]<<",";
		}
		sr++;
		for(i=sr; i<=er; i++)
		{
			cout<<arr[i][ec]<<",";
		}
		ec--;
		for(i=ec; i>=sc; i--)
		{
			cout<<arr[er][i]<<",";
		}
		er--;
		for(i=er; i>=sr; i--)
		{
			cout<<arr[i][sc]<<",";
		}
		sc++;
	}
	cout<<"\b\b";
}

int main()
{
	int arr[4][4] = {{11, 12, 13, 14}, {15, 16, 17, 18}, {19, 20, 21, 22}, {23, 24, 25, 26}};
        print_helical_matrix(arr, 4, 4);
	return 0;
}	
