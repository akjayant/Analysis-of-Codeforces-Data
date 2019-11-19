// I am grateful to everyone who taught or motivated me to code.
// Without your support, nothing would have been done.
using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#ifdef SEM_LOCAL
bool DEBUG = true;
#else
bool DEBUG = false;
#endif
#define FAST {ios::sync_with_stdio(0);cin.tie(0);cout<<setprecision(10)<<fixed;}
#define FOR(a,b,c) for(int a=(b); a<(int)(c); ++a)
#define DB(a) if(DEBUG) cerr<<#a<<" "<<a<< "\n";
#define all(v) (v).begin(),(v).end()
using ll = long long;
using ull = unsigned long long;
int MAXINT=2e9;
ll MAXLL=9e18;

// Includes
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// Variables

// Functions
class disj
{
public:

    vector<int> dat;

    int find(int from)
    {
        if (from == dat[from])
        {
            return from;
        }
        else
        {
            int t = find(dat[from]);
            dat[from] = t;
            return t;
        }
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (rand() % 2) swap(a,b);
        dat[a] = b;
    }
};

struct road{
    ll i;
    ll u;
    ll val;
};

bool operator< (road a, road b)
{
    return a.val < b.val;
}

// Main
int main() {
    //#ifdef SEM_LOCAL
    //    ifstream cin("tortsis.txt");
    //    ofstream cout("tortval.txt");
    //#endif
    FAST
    //

    disj disobj;
    vector<int> data(3000);
    FOR(i,0,3000)
        data[i] = i;
    disobj.dat = data;

    ll n; cin >> n;
    vector<ll> x(n+1,0);
    vector<ll> y(n+1,0);
    vector<vector<ll>> cost(n+1, vector<ll> (n+1, MAXINT));
    vector<ll> multr(n+1, 0);

    vector<road> ar;

    // COORDS
    FOR(i,1,n+1)
    {
        cin >> x[i] >> y[i];
    }

    // BUILDCOST
    FOR(i,1,n+1)
    {
        cin >> cost[0][i];
        cost[i][0] = cost[0][i];
        ar.push_back({0,i,cost[0][i]});
    }

    // MULT
    FOR(i,1,n+1)
    {
        cin >> multr[i];
    }

    // CALC
    FOR(i,1,n+1)
    {
        FOR(u, 1, n + 1)
        {
            cost[i][u] = (multr[i] + multr[u]) * (abs(x[i] - x[u]) + abs(y[i] - y[u]));
            if (u > i)
            {
                ar.push_back({i,u,cost[i][u]});
            }
        }
    }



    // Min tree
    sort(all(ar));
    vector<road> ans;
    for(road now : ar)
    {
        if (disobj.find(now.i) != disobj.find(now.u))
        {
            ans.push_back(now);
            disobj.unite(now.i, now.u);
        }

        if (ans.size() == n)
            break;
    }

    ll ansyen = 0;
    for(auto a : ans) ansyen += a.val;
    cout << ansyen << '\n';

    vector<int> build;
    for(auto a : ans)
    {
        if (a.i == 0)
            build.push_back(a.u);
    }

    cout << build.size() << '\n';
    FOR(i,0,build.size())
        cout << build[i] << ' ';
    cout << '\n';

    cout << ans.size() - build.size() << '\n';
    for(auto a : ans)
    {
        if (a.i != 0)
            cout << a.i << ' ' << a.u << '\n';
    }
}
