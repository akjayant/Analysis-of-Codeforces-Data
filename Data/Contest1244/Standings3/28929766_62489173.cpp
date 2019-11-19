//
//  main.cpp
//  A
//
//  Created by Dmitriy Timoshin on 20/07/2019.
//  Copyright © 2019 Dmitriy Timoshin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

vector<vector<int64_t>> col1;
vector<int64_t> col2;
vector<vector<int64_t>> tree;
vector<int64_t> used;
deque<pair<int64_t, int64_t>> que;
int64_t n;

pair<int64_t, vector<int64_t>> f(int64_t val1, int64_t val2)
{
    used = vector<int64_t>(n, 0);
    used[0] = val1;
    int64_t ans = 0;
    int64_t u = tree[0][0];
    used[u] = val2;
    ans += col1[val1 - 1][0];
    ans += col1[val2 - 1][u];
    int64_t val3;
    if (val1 != 1 && val2 != 1)
        val3 = 1;
    if (val1 != 2 && val2 != 2)
        val3 = 2;
    if (val1 != 3 && val2 != 3)
        val3 = 3;
    que.push_back({0, val3});
    que.push_back({u, val3});
    while (que.size() != 0)
    {
        auto [v, col] = que[0];
        que.pop_front();
        for (int64_t i = 0; i < tree[v].size(); ++i)
        {
            u = tree[v][i];
            if (used[u] == 0)
            {
                used[u] = col;
                ans += col1[col - 1][u];
                val1 = used[v];
                val2 = used[u];
                if (val1 != 1 && val2 != 1)
                    val3 = 1;
                if (val1 != 2 && val2 != 2)
                    val3 = 2;
                if (val1 != 3 && val2 != 3)
                    val3 = 3;
                que.push_back({u, val3});
            }
        }
    }
    return {ans, used};
}

int main() {
    cin >> n;
    int64_t a;
    tree.resize(n);
    col2 = vector<int64_t>();
    for (int64_t i = 0; i < n; ++i)
    {
        cin >> a;
        col2.push_back(a);
    }
    col1.push_back(col2);
    col2 = vector<int64_t>();
    for (int64_t i = 0; i < n; ++i)
    {
        cin >> a;
        col2.push_back(a);
    }
    col1.push_back(col2);
    col2 = vector<int64_t>();
    for (int64_t i = 0; i < n; ++i)
    {
        cin >> a;
        col2.push_back(a);
    }
    col1.push_back(col2);
    for (int64_t i = 0; i < n - 1; ++i)
    {
        int64_t b, c;
        cin >> b >> c;
        tree[b - 1].push_back(c - 1);
        tree[c - 1].push_back(b - 1);
    }
    for (int64_t i = 0; i < n; ++i)
    {
        if (tree[i].size() >= 3)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (n == 1)
    {
        cout << min(min(col1[0][0], col1[1][0]), col1[2][0]);
        return 0;
    }
    int64_t ans = 1e18;
    vector<int64_t> ans3;
    pair<int64_t, vector<int64_t>> p;
    p = f(1, 2);
    auto qwerty = p.first;
    auto qwerty2 = p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    p = f(1, 3);
    qwerty = p.first;
    qwerty2 = p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    p = f(2, 1);
    qwerty = p.first;
    qwerty2 = p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    p = f(2, 3);
    qwerty = p.first;
    qwerty2= p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    p = f(3, 1);
    qwerty = p.first;
    qwerty2= p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    p = f(3, 2);
    qwerty = p.first;
    qwerty2= p.second;
    if (qwerty < ans)
    {
        ans = min(ans, qwerty);
        ans3 = qwerty2;
    }
    cout << ans << endl;
    for (int64_t i = 0; i < ans3.size(); ++i)
    {
        cout << ans3[i] << " ";
    }
}
