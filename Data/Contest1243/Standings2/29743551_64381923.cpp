#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int>vec;
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])
                vec.push_back(i);
        if(vec.size()!=2) cout<<"No\n";
        else if(s[vec[0]]==s[vec[1]] && t[vec[1]]==t[vec[0]]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
