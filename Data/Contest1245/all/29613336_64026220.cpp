//
//  main.cpp
//  B
//
//  Created by Dmitriy Timoshin on 01/11/2019.
//  Copyright © 2019 Dmitriy Timoshin. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> ar;
    vector<int64_t> cost;
    vector<int64_t> cost2;
    set<vector<int64_t>> s;
    int64_t ans = 0;
    int64_t numst = 0;
    int64_t numsoed = 0;
    vector<pair<int64_t, int64_t>> ans2;
    vector<int64_t> station;
    vector<int64_t> used = vector<int64_t>(n, 0);
    vector<vector<int64_t>> dist = vector<vector<int64_t>>(n, vector<int64_t>(4, 1e18));
    int64_t cnt = 0;
    for (int64_t i = 0; i < n; ++i)
    {
        int64_t x, y;
        cin >> x >> y;
        ar.push_back({x, y});
    }
    for (int64_t i = 0; i < n; ++i)
    {
        int64_t a;
        cin >> a;
        cost.push_back(a);
        s.insert({a, 0, i, -1});
        dist[i] = {a, 0, i, -1};
    }
    for (int64_t i = 0; i < n; ++i)
    {
        int64_t a;
        cin >> a;
        cost2.push_back(a);
    }
    int64_t a, b, c, d;
    vector<int64_t> qwerty = *(s.begin());
    while (cnt != n)
    {
        cnt += 1;
        a = qwerty[0];
        b = qwerty[1];
        c = qwerty[2];
        d = qwerty[3];
        ans += a;
        used[c] = 1;
        if (b == 1)
        {
            numsoed += 1;
            ans2.push_back({c, d});
        }
        else
        {
            numst += 1;
            station.push_back(c);
        }
        for (int64_t i = 0; i < n; ++i)
        {
            if (used[i] == 0)
            {
                if (dist[i][0] > (abs(ar[c].first - ar[i].first) + abs(ar[c].second - ar[i].second)) * (cost2[i] + cost2[c]))
                {
                    dist[i][0] = (abs(ar[c].first - ar[i].first) + abs(ar[c].second - ar[i].second)) * (cost2[i] + cost2[c]);
                    dist[i][1] = 1;
                    dist[i][2] = i;
                    dist[i][3] = c;
                }
            }
        }
        int64_t nextdist = 1e18;
        for (int64_t i = 0; i < n; ++i)
        {
            if (used[i] == 0)
            {
                if (dist[i][0] < nextdist)
                {
                    nextdist = dist[i][0];
                    qwerty = dist[i];
                }
            }
        }
    }
    cout << ans << endl;
    cout << numst << endl;
    for (int64_t i = 0; i < numst; ++i)
    {
        cout << station[i] + 1 << " ";
    }
    cout << endl;
    cout << numsoed << endl;
    for (int64_t i = 0; i < numsoed; ++i)
    {
        cout << ans2[i].first + 1 << " " << ans2[i].second + 1 << endl;;
    }
    return 0;
}
