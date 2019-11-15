#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e9+7

int main()
{
    int q,n;
    cin>>q;
    string s,t;
    while(q--)
    {
        cin>>n;
        cin>>s>>t;
        int cnt=0;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                cnt++;
                v.push_back(i);
            }
        }
        if(cnt!=2)
        {
            cout<<"No\n";
        }
        else
        {
            int x=v[0];
            int y=v[1];
            if(s[x]==s[y]&&t[y]==t[x])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
