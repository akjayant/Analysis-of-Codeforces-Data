#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <queue>
using namespace std;
 
int gcd(int big, int small) {
    if (big % small ==0) return small;
    else return gcd (small, big% small);
}

int main() {
    int t, n, a, b, c, m;
    cin >> t;
    string s;
    for (int j = 0; j < t; ++j) {
        cin >> n >> a >> b >> c;
        m = 0;
        vector<int>ans(n, -1);
        cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (b > 0) {
                    --b;
                    ans[i] = 1;
                    ++m;
                }
            } else if (s[i] == 'P') {
                if (c > 0) {
                    --c;
                    ans[i] = 2;
                    ++m;
                }
            }
            else {
                if (a > 0) {
                    --a;
                    ans[i] = 0;
                    ++m;
                }
            }
        }
        if ((n + 1) / 2 <= m) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                if (ans[i] == 0) cout << 'R';
                else if (ans[i] == 1) cout << 'P';
                else if (ans[i] == 2) cout << 'S';
                else {
                    if (a > 0) {
                        cout << 'R';
                        --a;
                    }
                    else if (b > 0) {
                        cout << 'P';
                        --b;
                    }
                    else {
                        cout << 'S';
                    }
                }
            }
            cout << endl;
        } else cout << "NO\n";
    }
    
    return 0;
}
