#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//The Program below calculates and prints factorial of a number n using recursion(n<26)
//you can use long double in place of long long int to increase it's range
ll factorial(ll n){
    return(n==1 || n==0)? 1 : n*factorial(n-1);
}

int main(){
    ll n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}
