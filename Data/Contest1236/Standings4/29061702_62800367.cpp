#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;

vector<int> a[310];

void divide(int cnt, int grp_cnt) {
    int t = cnt / grp_cnt / 2;
    for (int i = 0; i < grp_cnt; i++) {
        for (int j = 0; j < t; j++) {
            a[i].push_back(i * t + j);
            a[i].push_back(cnt - 1 - (i * t + j));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        divide((n - 1) * n, n);
        for (int i = 0; i < n; i++)
            a[i].push_back((n - 1) * n + i);
    } else {
        divide(n * n, n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] + 1 << " ";
        cout << "\n";
    }

    return 0;
}

