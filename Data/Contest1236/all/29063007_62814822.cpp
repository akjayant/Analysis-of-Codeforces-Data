#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, k;
vector<int> col[N], row[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for (int i = 1; i < N; i++) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }
    int cells = n * m - k - 1;
    int up_row = 0, left_col = 0, down_row = n + 1, right_col = m + 1;
    int direction = 1;
    int x = 1, y = 1;
    int last_x = -1, last_y = -1;
    while (1) {
        if (direction == 1) {
            auto it = upper_bound(row[x].begin(), row[x].end(), y);
            int z = m + 1;
            if (it != row[x].end())
                z = *it;
            int n_y = min(right_col - 1, z - 1);
            cells -= n_y - y;
            direction = 2;
            up_row = x;
            y = n_y;
        }
        else if (direction == 2) {
            auto it = upper_bound(col[y].begin(), col[y].end(), x);
            int z = n + 1;
            if (it != col[y].end())
                z = *it;
            int n_x = min(down_row - 1, z - 1);
            cells -= n_x - x;
            direction = 3;
            right_col = y;
            x = n_x;
        }
        else if (direction == 3) {
            auto it = upper_bound(row[x].begin(), row[x].end(), y);
            int z = 0;
            if (row[x].size() && it != row[x].begin()){
                it--;
                z = *it;
            }
            int n_y = max(left_col + 1, z + 1);
            cells -= abs(n_y - y);
            direction = 4;
            down_row = x;
            y = n_y;
        }
        else if (direction == 4) {
            auto it = upper_bound(col[y].begin(), col[y].end(), x);
            int z = 0;
            if (col[y].size() && it != col[y].begin()){
                it--;
                z = *it;
            }
            int n_x = max(up_row + 1, z + 1);
            cells -= abs(n_x - x);
            direction = 1;
            left_col = y;
            x = n_x;
        }
        if (x == last_x && y == last_y)
            break;
        last_x = x, last_y = y;
    }
    if (cells)
        cout <<"No";
    else cout << "Yes";
    return 0;
}