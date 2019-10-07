
#include<iostream>
using namespace std
// Calculate the 'n'th term of fibonacci sequence recursive way
//Algorithm Complexity -> O(2^n)
int fib(int n)
{
	if(n<=1)
		return 0;	
	else
	{
		return (fib(n-1) + fib(n-2));
	}
}
int main()
{
	int n;
	cin >> n;
	cout << fib(n);
	return 0;
}

////////////////////////////////////////////////////////////////
// DP solution 
// Complexity O(n)
int main()
{
	int n;
	cin >> n; 
	int arr[n];
	arr[0]=0;
	arr[1]=1;
	// initialise the entire array to contain ith fibonacci at (i-1)th index
	for(int i=2;i<n;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	cout << arr[n-1];
}