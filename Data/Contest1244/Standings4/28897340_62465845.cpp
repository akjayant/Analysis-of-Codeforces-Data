#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

#define int64 long long
#define pii pair <int64, int64>
#define fr first
#define sc second
#define heap priority_queue
struct piii{
    int64 fr, sc, th;
    bool operator < (const piii &b){
        if (fr != b.fr) return fr < b.fr;
        if (sc != b.sc) return sc < b.sc;
        return th < b.th;
    }
};
///////////////////////////////////////////////
///////////////////////////////////////////////

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t, a, b, c, d, k;
    cin >> t;
    while (t--){
        cin >> a >> b >> c >> d >> k;
        int aa, bb;
        bool ok = false;
        for (int i = 0; i <= k; i++)
        if (c * i >= a && d * (k - i) >= b){
            ok = true;
            aa = i;
            bb = k - i;
        }
        if (!ok) cout << -1 << endl;
        else cout << aa << ' ' << bb << endl;
    }
    return 0;
}
