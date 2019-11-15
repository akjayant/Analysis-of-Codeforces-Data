#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define test() int t;cin>>t;loop(test,1,t+1)
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define nl cout<<"\n"
#define sp cout<<" "
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define MOD 1000000007
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

unordered_map<long long, int, custom_hash> safe_map;

const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();

    test()
    {
        int n, r, p, s, wins = 0;
        cin>>n>>r>>p>>s;
        string t;
        cin>>t;
        string ans = "";

        vector<int>rock,pap,sci;
        for(int i=0;i<n;i++)
        {
            if( t[i] == 'R' )
            {
                rock.pb(i);
            }
            else if( t[i] == 'P' )
            {
                pap.pb(i);
            }
            else if( t[i] == 'S' )
            {
                sci.pb(i);
            }
            ans += "X";
        }
        int rsz = rock.size();
        int psz = pap.size();
        int ssz = sci.size();
        for(int i=0;i<min(rsz,p);i++)
        {
            ans[rock[i]] = 'P';
        }
        wins += min(rsz,p);
        p -= min(rsz,p);

        for(int i=0;i<min(psz,s);i++)
        {
            ans[pap[i]] = 'S';
        }
        wins += min(psz,s);
        s -= min(psz,s);


        for(int i=0;i<min(ssz,r);i++)
        {
            ans[sci[i]] = 'R';
        }
        wins += min(ssz,r);
        r -= min(ssz,r);

        for(int i=0;i<n;i++)
        {
            if( ans[i] == 'X' )
            {
                if( r > 0 )
                {
                    ans[i] = 'R';
                    r--;
                }
                else if( p > 0 )
                {
                    ans[i] = 'P';
                    p--;
                }
                else if( s > 0 )
                {
                    ans[i] = 'S';
                    s--;
                }
            }
        }

        if( wins*2 >= n )
        {
            cout<<"YES\n";
            cout<<ans,nl;
        }
        else
            cout<<"NO\n";
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}