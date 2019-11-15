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

int n;
vector <int> res[303];

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1, cur = 0, d = 1; i <= n * n; i++){
        cur += d;
        if (cur > n) cur = n, d = -1;
        if (cur < 1) cur = 1, d = 1;
        res[cur].push_back(i);
    }
    for (int i = 1; i <= n; i++, cout << endl){
        for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
    }
    return 0;
}
