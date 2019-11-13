#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int n;
int a[305][305];
deque<int> d;

main () {
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        d.pb(n * n - i + 1);
    }

    for (int i = n; i >= 1;i --) {
        for (int j = 1; j <= n; j ++)
            a[j][i] = d[j - 1],d[j - 1] -= n;
        reverse(d.begin(),d.end());
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

