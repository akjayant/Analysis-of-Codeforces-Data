#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    long long a,b,k,t;
    a=0;
    b=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        k=(a+b)%1000000007;
        a=b;
        b=k;
    }
    a=0;
    b=1;
    for(int i=0;i<m;i++)
    {
        t=(a+b)%1000000007;
        a=b;
        b=t;
    }
    cout<<(k+t-1)*2%1000000007;

}