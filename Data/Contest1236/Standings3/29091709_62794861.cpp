//g++  5.4.0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    vector<vector<int>>a(n+1);
    ll j=1;
    ll r=1;
    ll f=0;
    for(int i=1;i<=n*n;++i)
    {
        a[j].push_back(i);
        j+=r;
        if(j==n+1 && f==0)
        {
            j--;
            f=1;
        }
        else if(j==n+1)
        {
            r=-1;
            j-=2;
            f=0;
        }
        if(j==0 && f==0)
        {
            j=1;
            f=1;
        }
        else if(j==0)
        {
            r=1;
            f=0;
            j+=2;
        }
        
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<a[i].size();++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}