#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;


#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define pii pair<int,int>
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vip vector<pair<int,int> >
#define ff first
#define ss second
#define int long long
#define mod 1000000007
#define BIG 998244353
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
#define mii map<int,int>
#define MSET(table,i) memset(table, i, sizeof(table))
#define endl '\n'
#define tc int t;cin>>t;while(t--)
#define pi  3.1415926358
#define bits(x) __builtin_popcount(x)
#define minimum(a,n) min_element(a,a+n)-a
#define maximum(a,n) max_element(a,a+n)-a
#define pqbig priority_queue<int>
#define pqsmall priority_queue<pii,vector<pii>,greater<pii> >
#define all(v) v.begin(),v.end()
#define sitr set<int>:: iterator
#define mitr map<int,int>:: iterator


#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


int32_t main()
{
    fast;
    tc
    {
        int n;cin>>n;
        string s,t;cin>>s>>t;
        string a=s;
        string b=t;
        sort(all(a));
        sort(all(b));
        int cnt=0;
        char c1,c2,c3,c4;

        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(cnt==1)
                    c3=s[i],c4=t[i];
                else if(cnt==0)
                    c1=s[i],c2=t[i];
                cnt++;
            }
        }

        //trace4(c1,c2,c3,c4);

        if(cnt==2 and c1==c3 and c2==c4)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
