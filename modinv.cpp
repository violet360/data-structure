#include <iostream>
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int d,x,y;
int modInverse(int A, int M)
{
    extendedEuclid(A,M); // Calculating modulo inverse using extended Euclidean algorithm  
    return (x%M + M)%M;    //x may be negative
}


int main() 
{
	int a,m; //we want to calculate modulo inverse of 'a' w.r.t. 'm'
	cin >> a >> m;
	cout << modInverse(a,m);
	return 0;   
}
