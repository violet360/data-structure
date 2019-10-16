#include <iostream>

using namespace std;
long long pisano_num(long long m,long long n)
{
    long long a=0,b=1,c=a+b;
    if(n>=m){
    for(long long i=0;i<m*m;i++)
    {
        c=(a+b)%m;
        a=b;
        b=c;
        if(a==0&&b==1)
            return i+1;
    }
    }
    else{
        for(long long i=0;i<n;i++)
    {
        c=(a+b)%m;
        a=b;
        b=c;
    }
    return a;
}
}
int fibonacci_fast(long long m, long long n) {
     long long a=1,b=1,t=0;
    for(int i=1;i<=n;i++){
        t=a;
        a=b;
        b=t+b;
        b=b%m;
    }
    return t;
}
int main()
{
    long long n,m;
    cin>>n>>m;
   if(n>=m)
    cout<<fibonacci_fast(m,(n%pisano_num(m,n)))<<endl;
    else
        cout<<pisano_num(m,n)%m<<endl;
    return 0;
}
