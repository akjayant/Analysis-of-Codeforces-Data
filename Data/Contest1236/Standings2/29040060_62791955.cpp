#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> v[n]={};
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            int g=0;
            for(int j=(i-1)*n+1;j<=i*n;j++)
            {
                v[g++].push_back(j);
            }
        }
        else
        {
            int g=n-1;
            for(int j=(i-1)*n+1;j<=i*n;j++)
            {
                v[g--].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j:v[i])
            cout<<j<<" ";
        cout<<endl;
    }
}