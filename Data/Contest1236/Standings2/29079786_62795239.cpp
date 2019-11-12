#pragma comment(linker, "/STACK:134217728") //128mb
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;


typedef long long ll;
const long long MOD = 1000000007; //1e9+7
const long long MAXN = 100000 + 100; //1e5

int calc(const vector<int>&a, const vector<int>&b) {
    int ia = 0, ib = 0;
    int res = 0;
    while (ib < b.size()) {
        while (ia < a.size() && a[ia] < b[ib]) {
            ia++;
        }
        res += ia;
        ib++;
    }
    return res;
}

int calc(const vector<vector<int>>& vec) {
    int n = vec.size();
    int mn = 9999999;
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0 ; j < n; ++j) {
            if (i==j)continue;
            mn = min(mn, calc(vec[i], vec[j]));
        }
    }
    return mn;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res(n);
    int beg = 1;
    int end = n*n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j&1) {
                res[i].push_back(j*n+1+i);
            } else {
                res[i].push_back((j+1)*(n)-i);
            }
        }
    }
    for (auto& v : res) {
        sort(v.begin(), v.end());
    }
//    cout << (calc(res) == (n*n)/2) << endl;
    for (int i =0 ; i < n; ++i) {
        for (int j =0 ; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
