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

int bestans = 1;
int besti = 0; // 0-not
int bestu = 0; // 0-not

void updans(ll myans, ll myi, ll myu)
{
    if (bestans < myans)
    {
        bestans = myans;
        besti = myi;
        bestu = myu;
    }
}

ll prefdif(vector<int>& pref, int pos0, int pos1)
{
    if (pos0 == -1)
        return pos1;
    return pref[pos1] - pref[pos0];
}

// Main
int main() {
//#ifdef SEM_LOCAL
//    ifstream cin("tortsis.txt");
//    ofstream cout("tortval.txt");
//#endif
    FAST
    //

    int n; cin >> n;
    string d; cin >> d;

    int gminbal = 1e7;
    int gbalance = 0;
    FOR(i,0,n)
    {
        if (d[i] == '(')
            gbalance++;
        else
            gbalance--;
    }
    if (gbalance != 0)
    {
        cout << "0\n1 1";
        return 0;
    }
    if (n == 2)
    {
        cout << "1\n1 1";
        return 0;
    }

    vector<int> curbal(n,0);
    curbal[0] = (d[0] == '(' ? 1 : -1);
    gminbal = min(gminbal, curbal[0]);
    FOR(i,1,d.size())
    {
        curbal[i] = curbal[i-1] + (d[i] == '(' ? 1 : -1);
        gminbal = min(gminbal, curbal[i]);
    }

    vector<vector<int>> mpref (3, vector<int> (n,0)); // mpref[delta][pos]
    // How many elements gminbal + delta before pos (incl.)
    FOR(delta,0,3)
    {
        FOR(pos,0,d.size())
        {
            mpref[delta][pos] = (curbal[pos] == gminbal + delta ? 1 : 0);
            if (pos != 0)
                mpref[delta][pos] += mpref[delta][pos-1];
        }
    }

    updans(mpref[0][n - 1], 0, 0);

    FOR(pos0, 0, n)
    {
        FOR(pos1, pos0 + 1, n)
        {
            if (d[pos0] == d[pos1])
                continue;
            int delta = 0;
            if (d[pos0] == '(')
                delta = -2;
            else
                delta = 2;

            int newmin = 1e7;
            FOR(i,0,n)
            {
                int el = curbal[i];
                if (i >= pos0 && i < pos1)
                    el += delta;
                newmin = min(newmin, el);
            }

            int newmins = 0;
            FOR(i,0,n)
            {
                int el = curbal[i];
                if (i >= pos0 && i < pos1)
                    el += delta;
                if (el == newmin) newmins++;


            }

            updans(newmins, pos0, pos1);
        }
    }
    cout << bestans << '\n';
    cout << besti + 1 << ' ' << bestu + 1;
}
