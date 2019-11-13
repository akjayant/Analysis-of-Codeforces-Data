#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main()
{
    c_p_c();
    string s; cin>>s;
    vector<pair<char,int> > v;

    for(auto ch : s)
    {
        if(v.empty() || v.back().ff!=ch)
            v.pb({ch,1});
        else
        {
            int id = v.size()-1;
            v[id].ss++;
        }

        if(ch=='m' || ch=='w')
        {
            cout<<0<<'\n';
            return 0;
        }
    }

    int ans=1;

    for(auto el : v)
    {
        if(el.ff!='n' && el.ff != 'u')
            continue;

        if(el.ss==1)
            continue;

        int dp[el.ss][2];

        dp[0][0]=1;
        dp[0][1]=0;

        for(int i=1;i<el.ss;++i)
        {
            dp[i][0] = (dp[i-1][1]+dp[i-1][0])%mod;
            dp[i][1] = dp[i-1][0];
        }

        int cur = (dp[el.ss-1][0]+dp[el.ss-1][1])%mod;

        ans = (ans*cur)%mod;
    }

    cout << ans << '\n';
    return 0;
}