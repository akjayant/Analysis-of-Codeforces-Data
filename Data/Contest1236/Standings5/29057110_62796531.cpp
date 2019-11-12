#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector <vector <int> > ans(n, vector <int> (n));

    int flag = 0, r = 0;
    vector <int> a;
    for(int i = 1; i <= n * n; i++) {
        int x = i;

        a.push_back(x);

        if (a.size() == n) {
            if (flag) {
                for(int q = 0; q < n; q++) {
                    ans[q][r] = a.back();
                    a.pop_back();
                }
            }
            else {
                reverse(a.begin(), a.end());
                for(int q = 0; q < n; q++) {
                    ans[q][r] = a.back();
                    a.pop_back();
                }
            }

            flag ^= 1;
            r++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
/*
*/
