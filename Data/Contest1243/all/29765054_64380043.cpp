#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define whole(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = int(1e5) + 2;
const int LG = 20;
const ll mod = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const ll linf = 1e13;
const ld pi = acos(-1);
const int base = 10;
const ld EPS = 1e-9;

int tt;
int main (){
    cin >> tt;
    while (tt--){
        int n;
        string a, b;
        cin >> n;
        cin >> a >> b;
        int cnt = 0, pos1 = -1, pos2 = -1;
        for (int i = 0; i < n; ++i){
            if (a[i] != b[i]){
                if (cnt == 0){
                    pos1 = i;
                } else {
                    pos2 = i;
                }
                ++cnt;
            }
        }
        if (cnt > 2){
            cout << "No\n";
            continue;
        }
        swap(a[pos1], b[pos2]);
        if (a == b){
            cout << "Yes\n";
            continue;
        }
        swap(a[pos1], b[pos2]);
        swap(b[pos1], a[pos2]);
        if (a == b){
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}
