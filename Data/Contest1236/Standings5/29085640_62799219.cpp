#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> group(N);
    int now = N * N;
    rep(i, 0, N) {
        if (i % 2) {
            rep(j, 0, N) {
                group[j].push_back(now--);
            }
        }
        else {
            rrep(j, N, 0) {
                group[j].push_back(now--);
            }
        }
    }
    rep(i, 0, N) {
        rep(j, 0, N) cout << group[i][j] << ' ';
        cout << endl;
    }
    return 0;
}