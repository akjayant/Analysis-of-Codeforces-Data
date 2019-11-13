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

void erase( deque<pii>&v, pii x )
{
    for(int k=0;k<v.size();k++)
    {
        if( v[k] == x )
        {
            v.erase(v.begin()+k);
            break;
        }
    }
}

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();

    test()
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;

        int fr[26]={}, fr2[26]={};
        deque<pii>ind[26];
        for(int i=0;i<n;i++)
        {
            fr[s[i]-'a']++;
            fr2[t[i]-'a']++;
            ind[s[i]-'a'].pb({i,0});
            ind[t[i]-'a'].pb({i,1});
        }

        int bad = 0;
        for(int c=0;c<26;c++)
        {
            if( (fr[c] + fr2[c])%2 != 0 )
            {
                bad = 1;
                break;
            }
        }
        if( bad )
        {
            cout<<"NO\n";
        }
        else
        {
            vector<pii>ans;
            for(int i=0;i<n;i++)
            {
                if( s[i] == t[i] )
                    continue;

                int a = s[i]-'a', b = t[i]-'a';
                int pos = -1;
                for(int j=i+1;j<n;j++)
                {
                    if( s[j]-'a' == a )
                    {
                        pos = j;
                        break;
                    }
                }

                if( pos != -1 )
                {
                    ans.pb({pos,i});
                    swap(s[pos],t[i]);
                    continue;
                }

                for(int j=i+1;j<n;j++)
                {
                    if( t[j]-'a' == a )
                    {
                        pos = j;
                        break;
                    }
                }

                ans.pb({n-1,pos});
                swap(s[n-1],t[pos]);

                ans.pb({n-1,i});
                swap(s[n-1],t[i]);

            }

            cout<<"YES\n";
            cout<<ans.size(),nl;
            for( auto x : ans )
            {
                cout<<x.F+1<<" "<<x.S+1,nl;
            }
        }

    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}