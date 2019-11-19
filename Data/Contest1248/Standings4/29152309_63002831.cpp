#include<bits/stdc++.h>
using namespace std;
long long power(long long x, long long int y)
{
    long long res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%1000000007;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x)%1000000007;  // Change x to x^2
    }
    return res;}
int main(){
    long long n,m;
    cin>>n>>m;
    long long n1=max(n,m);
    long long m1=min(n,m);
    long long a[n1+1][2]={0};
    long long ty=2;
    //long long int p=2*(m1-1);
    a[1][0]=1;
    a[1][1]=1;
    a[2][0]=2;
    a[2][1]=2;
    long long int ans=0;
    for(int i=3;i<=n1;i++){
        a[i][0]=(a[i-1][1]+a[i-2][1])%1000000007;
        a[i][1]=(a[i-1][0]+a[i-2][0])%1000000007;
    }
    cout<<(a[n1][0]*2+a[m1][0]*2-2)%1000000007;
    return 0;
}
