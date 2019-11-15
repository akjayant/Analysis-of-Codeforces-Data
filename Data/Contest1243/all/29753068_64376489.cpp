#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main() {
    kekek;
    int k;
    cin >> k;
    while (k--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                pos.push_back(i);
            }
        }

        if (pos.size() == 0) {
            cout << "Yes";
        }
        else if (pos.size() == 2) {
            if (s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]]) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
        }
        else {
            cout << "No";
        }
        cout << '\n';
    }

    //system("pause");
    return 0;
}