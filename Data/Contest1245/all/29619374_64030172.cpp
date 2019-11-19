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
 


int main() {
    int n;
    cin >> n;
    vector<long long>x(n);
    vector<long long>y(n);
    vector<long long>cost_el(n);
    vector<long long>cable(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost_el[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cable[i];
    }
    vector<vector<long long>>connec(n, vector<long long>(n));
    vector<pair<int, int>>con;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            connec[i][j] = (cable[i] + cable[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            if (connec[i][j] == 0 && i < j) {
                con.push_back(make_pair(i + 1, j + 1));
            }
        }
    }
    int start = 0;
    long long v;
    long long mincost = 2000000000;
    for (int i = 0; i < n; ++i) {
        if (cost_el[i] < mincost) {
            mincost = cost_el[i];
            start = i;
        }
    }
    v = mincost;
    vector<pair<long long, int>>need(n);
    for (int i = 0; i < n; ++i) {
        need[i].first = connec[start][i];
        need[i].second = start;
    }
    for (int i = 0; i < n; ++i) {
        if (need[i].first > cost_el[i]) {
            need[i].first = cost_el[i];
            need[i].second = -1;
        }
    }
    long long mindis = 9000000000;
    vector<int>prov(1, start + 1);
    while (mindis != 8000000000) {
        mindis = 8000000000;
        for (int i = 0; i < n; ++i) {
            if (need[i].first > 0 && need[i].first < mindis) {
                mindis = need[i].first;
                start = i;
            }
        } if (mindis != 8000000000) {
            v += mindis;
            if (need[start].second == -1) {
                prov.push_back(start + 1);
            }
            else con.push_back(make_pair(need[start].second + 1, start + 1));
        }
        need[start].first = 0;
        for (int i = 0; i < n; ++i) {
            if (connec[start][i] < need[i].first) {
                need[i].first = connec[start][i];
                need[i].second = start;
            }
        }
    }
    cout << v << endl;
    cout << prov.size() << endl;
    for (int i = 0; i < prov.size(); ++i) {
        cout << prov[i] << " ";
    }
    cout << endl;
    cout << con.size() << endl;
    for (int i = 0; i < con.size(); ++i) {
        cout << con[i].first << " " << con[i].second << endl;
    }
    return 0;
}
