#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<long long>v(100000);
    v[0]=2;
    v[1]=4;
    for(int i=2; i<100000; i++)v[i]=(v[i-1]+v[i-2])%1000000007;
    cout<<(v[n-1]+v[m-1]+1000000005)%1000000007;
}
