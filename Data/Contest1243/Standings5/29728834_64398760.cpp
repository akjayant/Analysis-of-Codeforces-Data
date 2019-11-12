//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define y1 bbp
#define sz size()
using namespace std;
ll const N=1e6+7,inf=1e9+7;
ll a[N],b[N],qq,m,n,k,x,y,r,ans,q;
string s,t;
pair <ll,ll> p[N];
//vector <ll> ot,v;
ll us[N];
char ch;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>qq;
    for (int ii=0;ii<qq;ii++)
    {
        cin>>n>>s>>t;
        vector <pair<ll,ll> > ot;
        for (int i=0;i<s.sz;i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']++;
        }
        bool pr=0;
        for (int i=0;i<26;i++)
        {
            if (a[i]%2) pr=1;
            a[i]=0;
        }
        if (pr)
        {
            cout<<"No"<<endl;
            continue;
        }
        for (int i=0;i<n;i++)
        {
            if (s[i]==t[i]) continue;
            int ps=t.find(s[i],i+1);
            if (ps==string::npos)
            {
                ps=s.find(s[i],i+1);
                ot.pb({ps+1,i+1});
                swap(s[ps],t[i]);
            }
            else
            {
                ot.pb({ps+1,ps+1});
                ot.pb({ps+1,i+1});
                swap(t[ps],s[ps]);
                swap(s[ps],t[i]);
            }
        }
        if (s!=t)
        {
            cout<<"No"<<endl;
            continue;
        }
        if (ot.sz<=2*n)
        {
            cout<<"Yes"<<endl;
            cout<<ot.sz<<endl;
            for (int i=0;i<ot.sz;i++)
            {
                cout<<ot[i].f<<" "<<ot[i].s<<endl;
            }
        } else cout<<"No"<<endl;

    }
}
