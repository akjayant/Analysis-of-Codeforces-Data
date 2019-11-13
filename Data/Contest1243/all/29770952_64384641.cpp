#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    while(k--)
    {
        int n; cin>>n;
        string s,t; cin>>s>>t;
        vector<int> d;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i]) d.pb(i);
        }
        if(d.size()!=2) cout<<"No\n";
        else
        {
            if(s[d[0]]==s[d[1]] && t[d[0]]==t[d[1]]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}
