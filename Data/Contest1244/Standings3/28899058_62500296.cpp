#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

///assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<char> VEC1D;
typedef vector<VEC1D> VEC2D;
typedef vector<VEC2D> VEC3D;
typedef vector<ll> VEC1Dll;
typedef vector<VEC1Dll> VEC2Dll;
typedef vector<VEC2Dll> VEC3Dll;
typedef cc_hash_table<ll, ll, hash<ll>> ht;
typedef gp_hash_table<int, int> gt;

#define  pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,a,b) for(ll i = a; i<=b;i++)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define vll vector<ll>
#define tests() int test_cases ; cin >> test_cases ; while(test_cases--)
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define MAXN 100010
#define MOD 1000000007
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define sp " "
#define MS(x,y) memset(x,y,sizeof(x))
#define INF 1000000000000000000
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<char, int, custom_hash> safe_map;
gp_hash_table<long long, int, custom_hash> safe_hash_table;

vll adj[MAXN];
ll c[3][MAXN];
ll start;
ll fun(ll d1,ll d2,ll d3,ll ans[],ll n){
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    vis[start] = true;

    ll cost = 0;

    ll st = start;

    ans[st] = d1+1;
    cost+=c[d1][st];

    f(i,1,n){
        for(ll x: adj[st]){
            if(vis[x] == false){
                vis[x] = true;
                st = x;
                if(i%3 == 1){
                    ans[st] = d2+1;
                    cost+=c[d2][st];
                }
                else if(i%3 == 2){
                    ans[st] = d3+1;
                    cost+=c[d3][st];
                }
                else {
                    ans[st] = d1+1;
                    cost+=c[d1][st];
                }
                break;
            }
        }
    }
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;



    f(i,0,3){
        f(j,1,n+1){
            cin>>c[i][j];
        }
    }

    ll vis[n+1];
    memset(vis,0,sizeof(vis));

    bool sol_exists = true;

    f(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);

        vis[a]++;
        vis[b]++;

        if(vis[a]>2||vis[b]>2){
            sol_exists = false;
            break;
        }

    }

    if(sol_exists == false){
        cout<<-1<<endl;
        return 0;
    }
    f(i,1,n+1){
        if(vis[i] == 1){
            start = i;
            break;
        }
    }

    ll ans[n+1];

    ll tr[6];

    tr[0] = fun(0,1,2,ans,n),tr[1] = fun(0,2,1,ans,n),tr[2] = fun(1,0,2,ans,n),
    tr[3] = fun(1,2,0,ans,n),tr[4] = fun(2,0,1,ans,n), tr[5] = fun(2,1,0,ans,n);

    ll cost = LONG_LONG_MAX;

    ll d1[] = {0,0,1,1,2,2};
    ll d2[] = {1,2,0,2,0,1};
    ll d3[] = {2,1,2,0,1,0};

    f(i,0,6){
        cost = min(cost,tr[i]);
    }

    f(i,0,6){
        if(cost == tr[i]){
            if(cost == fun(d1[i],d2[i],d3[i],ans,n)){
                break;
            }
        }
    }

    cout<<cost<<endl;

    f(i,0,n){
        cout<<ans[i+1]<<" ";
    }

    return 0;
}
