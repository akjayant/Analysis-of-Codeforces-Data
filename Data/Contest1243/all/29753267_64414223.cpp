#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector< pair<char,char> >v;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])
                v.push_back({s[i],t[i]});
        if((int)v.size()!=2)
        {
            cout<<"No"<<'\n';
            continue;
        }
        if(v[0].first==v[1].first&&v[0].second==v[1].second)
            cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}
