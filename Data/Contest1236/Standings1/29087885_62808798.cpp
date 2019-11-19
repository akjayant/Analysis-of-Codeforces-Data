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
int dy[] = {0,-1,0,1};

vector<int>row[MAXN],col[MAXN];
ll n,m;

int lower_bound( vector<int>&a, int val, int lim )
{
    int lo = 0, hi = a.size()-1, mid, tans = lim;
    while( lo <= hi )
    {
        mid = lo + (hi-lo)/2;

        if( a[mid] >= val )
        {
            tans = a[mid];
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return min(tans,lim);
}

int upper_bound( vector<int>&a, int val, int lim )
{
    int lo = 0, hi = a.size()-1, mid, tans = lim;
    while( lo <= hi )
    {
        mid = lo + (hi-lo)/2;

        if( a[mid] <= val )
        {
            tans = a[mid];
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return max(tans,lim);
}

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();

    int k;
    cin>>n>>m>>k;

    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        row[x].pb(y);
        col[y].pb(x);
    }
    for(int i=0;i<MAXN;i++)
    {
        sort(all(row[i]));
        sort(all(col[i]));
    }
    int mxy = m, mxx = n, mny = -1, mnx = 0;
    int nowx = 0, nowy = 0, nowdir = 0;
    ll add = 1, prev = -1;
    while( 1 )
    {
        int go;
        ll now = 0;
        // cout<<nowdir<<" "<<nowx<<" "<<nowy<<" ";
        switch( nowdir )
        {
            case 0:
                go = lower_bound(row[nowx],nowy,mxy)-1;
                now += (go-nowy);
                mxy = min(mxy, go);
                nowy = go;
                break;
            case 1:
                go = lower_bound(col[nowy],nowx,mxx)-1;
                now += (go-nowx);
                mxx = min(mxx, go);
                nowx = go;
                break;
            case 2:
                go = upper_bound(row[nowx],nowy,mny)+1;
                now += (nowy-go);
                mny = max(mny, go);
                nowy = go;
                break;
            case 3:
                go = upper_bound(col[nowy],nowx,mnx)+1;
                now += (nowx-go);
                mnx = max(mnx, go);
                nowx = go;
                break;
        }
        add += now;
        if( add == prev )
        {
            break;
        }
        // cout<<now,nl;
        prev = add;
        nowdir = mod(nowdir+1,4);
    }

    if( add+k == n*m )
        cout<<"Yes";
    else
        cout<<"No";


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}