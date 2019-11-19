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
#define FAST {ios::sync_with_stdio(0);cin.tie(0);cout<<setprecision(30)<<fixed;}
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
#include <queue>

// Variables
struct stk
{
    int sn = -1;
    int pos = -1;
};

bool operator< (stk a, stk b)
{
    if (a.sn == b.sn)
        return a.pos < b.pos;
    return a.sn < b.sn;
}

// Functions
vector<set<stk>> where;
string a,b;

void remm(char c, int pos, int sn)
{
    for(auto it = where[c- 'a'].begin(); it != where[c- 'a'].end(); it++)
    {
        if (it->pos == pos && it->sn == sn)
        {
            where[c- 'a'].erase(it);
            break;
        }
    }
}

void addd(char c, int pos, int sn)
{
    where[c-'a'].insert({sn,pos});
}

vector<int> reca;
vector<int> recb;

void sswap(int ai, int bi)
{
    reca.push_back(ai+1);
    recb.push_back(bi+1);


    char ac = a[ai];
    char bc = b[bi];
    swap(a[ai], b[bi]);

    remm(ac, ai, 0);
    remm(bc, bi, 1);

    addd(bc, ai, 0);
    addd(ac, bi, 1);
}

// Main
int main() {
#ifdef SEM_LOCAL
    ifstream cin("sis.txt");
    ofstream cout("val.txt");
#endif
    FAST
    //
    vector<vector<int>> avoid(2e5);

    int n; int m;
    cin >> n >> m;
    FOR(iii,0,m)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        avoid[a].push_back(b);
        avoid[b].push_back(a);
    }
    FOR(i,0,n)
    {
        avoid[i].push_back(MAXINT);
        sort(all(avoid[i]));
    }

    int ans = -1;
    vector<bool> got(2e5, false);
    set<int> still;
    FOR(i,0,n)
        still.insert(i);
    FOR(i,0,n)
    {
        if (got[i] == true)
            continue;

        ans++; // New component
        queue<int> q;
        q.push(i);
        got[i] = true;
        still.erase(i);

        while(!q.empty())
        {
            int from = q.front();
            q.pop();

            vector<int> todel;
            int avoidp = 0;
            for(auto to : still)
            {
                while (avoid[from][avoidp] < to)
                    avoidp++;
                if (avoid[from][avoidp] == to)
                    continue;
                if (got[to] == true)
                    continue;

                got[to] = true;
                todel.push_back(to);
                q.push(to);
            }

            for(auto aaaaa : todel)
                still.erase(aaaaa);
        }
    }
    cout << ans;
}
