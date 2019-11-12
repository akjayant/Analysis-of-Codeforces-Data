#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int n, a[N][N];
vector <int> divi[N];
bool ok = false;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    /*vector <int> vec;
    for (int i = 1; i <= n * n; i++) vec.push_back(i);
    int total = 0;
    do {
        int ans = 1e9;
        for (int i = 0; i < vec.size(); i++) a[i / n][i % n] = vec[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int res = 0;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (a[i][k] > a[j][l]) res++;
                    }
                }

                ans = min(ans, res);
            }
        }

        if (ans == 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";
                }

                cout << "\n";
            }

            cout << "\n";
        }

        total = max(total, ans);
    } while (next_permutation(vec.begin(), vec.end()));
    //cout << total;*/

    int cnt = 1;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 1; j <= n; j++) {
            a[j][i] = cnt++;
        }
    }

    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            a[j][i] = cnt++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
