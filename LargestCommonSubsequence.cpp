#include <iostream>
#include<string.h>

using namespace std;
int lcs(int m, int n, char a, char b){
    int C[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0){
                C[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                C[i][j]=C[i-1][j-1]+1;
            }
            else
                C[i][j]=max(C[i-1][j],C[i][j-1]);
        }
    }
    return C[m][n];
}
int max(int m1, int m2){
    int largest=0;
    if(m1>m2)
        largest=m1;
    else
        largest=m2;
    return largest;
}
int main()
{
    char a[20];
    char b[20];

    cout<<"\n enter first string : ";
    cin>>a;
    cout<<"\n enter second string:  ";
    cin>>b;

    int m=strlen(a);
    int n=strlen(b);

    cout<<"\n Length of LCS = "<<lcs(m,n,a,b);
    return 0;
}
