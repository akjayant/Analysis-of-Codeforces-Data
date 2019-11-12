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
    int q; cin >> q;
    FOR(asrw3fe,0,q)
    {
        int n; cin >> n;
        string a, b;
        cin >> a >> b;
        vector<char> letters;
        FOR(i,0,n)
        {
            if (a[i] == b[i])
                continue;
            letters.push_back(a[i]);
            letters.push_back(b[i]);
        }
        if (letters.size() == 0)
            cout << "Yes\n";
        if (letters.size() == 4 && letters[0] == letters[2] && letters[1] == letters[3])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
