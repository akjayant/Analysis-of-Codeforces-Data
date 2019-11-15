#include<bits/stdc++.h>
 
using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e3 + 7;
 
int main() {
    cout.precision(20);
    cout << fixed;
    int n;
    cin >> n;
    int cur = 1;
    vector<int> answer[MAXN];
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                answer[j].push_back(cur);
                ++cur;
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                answer[j].push_back(cur);
                ++cur;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < answer[i].size(); ++j) cout << answer[i][j] << ' ' ;
        cout << endl;
    }
    return 0;
}