#include <bits/stdc++.h>
#define mn 10004
using namespace std;
int k,n;
string s,t;
vector<int> vt;
int main()
{
    cin>>k;
    while(k--)
    {
        vt.clear();
        cin>>n;
        cin>>s>>t;
        s=" "+s;
        t=" "+t;
        for(int i=1;i<=n;i++)
            if(s[i]!=t[i])
            vt.push_back(i);
        if(vt.size()==2)
        {
            if(s[vt[0]]==s[vt[1]]&&t[vt[0]]==t[vt[1]])
            {
                cout<<"Yes"<<'\n';
                continue;
            }
            else
            {
                cout<<"No"<<'\n';
                continue;
            }
        }
        if(vt.empty()){cout<<"Yes"<<'\n';continue;}
        cout<<"No"<<'\n';
    }
    return 0;
}
