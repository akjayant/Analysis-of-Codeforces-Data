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

const int64 md = 1e9 + 7;
int64 m, n;

int64 pw(int64 b, int64 a){
    if (a == 0) return 1;
    int64 tmp = pw(b, a / 2);
    tmp = (tmp * tmp) % md;
    if (a % 2) tmp = (tmp * b) % md;
    return tmp;
}

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int64 tmp = (pw(2, m) - 1 + md) % md;
    cout << pw(tmp, n);
    return 0;
}
