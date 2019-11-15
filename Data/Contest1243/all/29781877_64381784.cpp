#pragma GCC optimize "-O1"
#pragma GCC optimize "-O2"
#pragma GCC optimize "-O3"

#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

const int N = 300 * 1000 + 5;

void test() {
    int n;
    cin >> n;

    string s;
    map<char, int> ms;
    cin >> s;

    string t;
    cin >> t;

    int i;
    for (i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) break;
    }

    int j;
    for (j = t.length() - 1; j >= 0; j--) {
        if (s[j] != t[j]) break;
    }

    swap(s[i], t[j]);

    if (s == t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;

    }
}

int main() {
    int t;
    cin >> t;
    loop(i, t) test();
    return 0;
}
/*



*/