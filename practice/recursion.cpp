#include <iostream>
#include <iomanip>

using namespace std;

class recur
{
	public:
		int fibonacci(int n);
		int factorial(int n);
		int sumofdigits(int n);
};

int recur::fibonacci(int n)
{
	if(n<2)
		return n;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

int recur::factorial(int n)
{
	if(n<2)
		return 1;
	else
		return n*factorial(n-1);
}

int recur::sumofdigits(int n)
{
	if(n==0)
		return 0;
	else 
		return ((n%10)+(sumofdigits(n/10)));
}

int main()
{
	recur r1;
	int n;
	cout<<"enter no";
	cin>>n;
	cout<<"fibonacci value for "<<n<<" is :"<<r1.fibonacci(n)<<endl;
	cout<<"factorial value for "<<n<<" is :"<<r1.factorial(n)<<endl;
	cout<<"sum of the digits of "<<n<<" is :"<<r1.sumofdigits(n)<<endl;
	return 0;
}
