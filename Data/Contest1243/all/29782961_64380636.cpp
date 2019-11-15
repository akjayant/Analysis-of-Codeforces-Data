#include <iostream>
#include <algorithm>
#include <set>
#include "vector"
#include "queue"
#include <math.h>

using namespace std;

int main() {
    int k, n;
    string s, t;
    cin >> k;
    for (int q = 0; q < k; q++) {
        cin >> n;
        cin >> s;
        cin >> t;
        vector<int> ind;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                ind.push_back(i);
            }
        }
        if (ind.size() > 2 || ind.size() == 1) {
            cout << "NO\n";
            continue;
        }
        if (ind.empty()) {
            cout << "YES\n";
            continue;
        }
        if (s[ind[0]] != s[ind[1]] || t[ind[1]] != t[ind[0]]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

}
