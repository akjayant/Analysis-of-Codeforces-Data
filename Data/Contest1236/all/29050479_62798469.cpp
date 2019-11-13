#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18,mod=1e9+7,maxn=4e5+100;

int n,m,l,r,x,y,q,ans,res;

string s,t;

vector <int> v[maxn];
main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    int p=1,k=n*n;
    for(int j=0;j<n;j++)
    {
          for(int i=0;i<n;i++)
        if(j%2)v[i].push_back(p++);
        else v[i].push_back(k--);
    }
    for(int i=0;i<n;i++){
            for(auto j:v[i])
    cout << j << " ";
    cout << "\n";
    }


}
