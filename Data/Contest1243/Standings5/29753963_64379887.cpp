#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+5;
int n,m,q,dm;
vector<char> vt,vt2;
string s,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("1243B.inp","r",stdin);
    //freopen("1243B.out","w",stdout);
    cin>>q;
    while(q--)
    {
        int dem=0;
        cin>>n;
        cin>>s>>t;
        s=" "+s;
        t=" "+t;
        for (int i=1;i<=n;i++)
            if (s[i]!=t[i])
                dem++;
        if (dem==0)
        {
            cout<<"Yes"<<'\n';
            continue;
        }
        if (dem!=2)
            cout<<"No"<<'\n';
        else
        {
            vt.clear();
            vt2.clear();
            for (int i=1;i<=n;i++)
                if (s[i]!=t[i])
                {
                    vt.push_back(s[i]);
                    vt2.push_back(t[i]);
                }
            if (vt[0]!=vt[1] || vt2[0]!=vt2[1])
                cout<<"No"<<'\n';
            else cout<<"Yes"<<'\n';
        }
    }
}
