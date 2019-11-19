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

string s;
int n;

int main(){
    cout << setprecision(2) << fixed;
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> s;
        int mx = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        if (s[i] == '1'){
            mx = max(mx, max(n - i, i + 1));
            cnt++;
        }
        cout << max(n + cnt, mx * 2) << endl;
    }
    return 0;
}
