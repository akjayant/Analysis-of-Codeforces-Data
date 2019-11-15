#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define  int long long int
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll hell =1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        vector<char>t(n);
        int th=ceil((double)n/2);int mn;
        for(int i=0;i<n;i++)
            t[i]='X';
        int x=0,y=0,z=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
                x++;
            else if(s[i]=='P')
                y++;
            else
                z++;
        }
        int ans=min(a,z)+min(b,x)+min(c,y);
        if(ans>=th)
        {
            cout<<"YES"<<endl;
            mn=min(a,z);
            a-=mn;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='S'&&mn>0)
                {
                    t[i]='R';
                    mn--;
                }
            }
            mn=min(b,x);
            b-=mn;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='R'&&mn>0)
                {
                    t[i]='P';
                    mn--;
                }
            }
            mn=min(c,y);
            c-=mn;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='P'&&mn>0)
                {
                    t[i]='S';
                    mn--;
                }
            }
            for(int i=0;i<n;i++)
                if(t[i]=='X'&&a>0)
                {t[i]='R';a--;
                }
            for(int i=0;i<n;i++)
                if(t[i]=='X'&&b>0)
                {t[i]='P';b--;
                }
            for(int i=0;i<n;i++)
                if(t[i]=='X'&&c>0)
                {t[i]='S';c--;
                }
            for(int i=0;i<n;i++)
                cout<<t[i];
            cout<<endl;
            
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
