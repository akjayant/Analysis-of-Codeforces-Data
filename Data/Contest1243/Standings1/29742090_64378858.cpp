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
    cin>>t;int n;string s,t1;
    while(t--)
    {
        cin>>n;
        cin>>s>>t1;
        int cnt=0;vi v;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t1[i])
            {
                cnt++;
                v.pb(i);
            }
        }
        if(cnt==0)
        {
            cout<<"Yes";
        }
        else if(cnt==1)
        {
            cout<<"No";
        }
        else if(cnt==2)
        {
            int i1,i2;
            i1=v[0];i2=v[1];
            if(s[i1]==s[i2]&&(t1[i1]==t1[i2]))
                cout<<"Yes";
            else
                cout<<"No";
        }
        else
        {
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}
