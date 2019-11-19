#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 100010;

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int next(int dirx) {
    return (dirx + 1) % 4;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<int, int>> obstacles(k);
    vector<vector<int>> rows(n + 1), cols(m + 1);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &obstacles[i].first, &obstacles[i].second);
        rows[obstacles[i].first].push_back(obstacles[i].second);
        cols[obstacles[i].second].push_back(obstacles[i].first);
    }

    for (int i = 1; i <= n; i++) {
        rows[i].push_back(0);
        rows[i].push_back(m + 1);
        sort(rows[i].begin(), rows[i].end());
    }

    for (int i = 1; i <= m; i++) {
        cols[i].push_back(0);
        cols[i].push_back(n + 1);
        sort(cols[i].begin(), cols[i].end());
    }

    long long sum = 0;
    pair<int, int> cur = make_pair(1, 1);
    int curdir = 0;
    int up = 0, down = n + 1, left = 0, right = m + 1;
    while (true) {
        // printf("%d %d\n", cur.first, cur.second);
        if (dir[curdir].first) {
            int cury = cur.second;
            int idx = lower_bound(cols[cury].begin(), cols[cury].end(), cur.first) - cols[cury].begin();
            // printf("%d\n", idx);
            if (dir[curdir].first < 0) idx--;
            int end = max(up, min(down, cols[cury][idx]));
            int len = (end - cur.first) * dir[curdir].first;
            // printf("moving from %d to %d, len = %d\n", cur.first, end, len);
            if (len == 0) break;
            cur.first = end - dir[curdir].first;
            sum += len;
            if (dir[next(curdir)].second < 0) right = cur.second;
            else left = cur.second;
            // printf("%d %d\n", cur.first, cur.second);
        } else {
            int cury = cur.first;
            int idx = lower_bound(rows[cury].begin(), rows[cury].end(), cur.second) - rows[cury].begin();
            // printf("%d\n", idx);
            if (dir[curdir].second < 0) idx--;
            int end = max(left, min(right, rows[cury][idx]));
            int len = (end - cur.second) * dir[curdir].second;
            // printf("moving from %d to %d, len = %d\n", cur.second, end, len);
            if (len == 0) break;
            cur.second = end - dir[curdir].second;
            sum += len;
            if (dir[next(curdir)].first < 0) down = cur.first;
            else up = cur.first;
            // printf("%d %d\n", cur.first, cur.second);
        }
        curdir = next(curdir);
        cur.first += dir[curdir].first;
        cur.second += dir[curdir].second;
        // printf("%d %d\n", cur.first, cur.second);
        // printf("%d %d %d %d\n", down, up, right, left);
        if (cur.first >= down || cur.first <= up || cur.second >= right || cur.second <= left)
            break;
        if (binary_search(rows[cur.first].begin(), rows[cur.first].end(), cur.second))
            break;
        if (binary_search(cols[cur.second].begin(), cols[cur.second].end(), cur.first))
            break;
    }

    if (sum == (long long)n * m - k) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
