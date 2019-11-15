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

int t, a, b, c;

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        int res = 0;
        for (int i = 0; i <= min(a, b / 2); i++){
            int tmp = min(b - 2 * i, c / 2);
            res = max(res, i * 3 + tmp * 3);
        }
        cout << res << endl;
    }
    return 0;
}
