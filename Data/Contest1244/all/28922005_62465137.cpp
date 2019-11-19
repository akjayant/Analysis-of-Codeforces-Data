#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
int main() {
    int t;
    cin >> t;
    for(int tt = 0; tt < t; ++tt) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int need = ceil(1. * a / c) + ceil(1. * b / d);
        if(need > k) {
            cout << -1 << "\n";
        } else {
            cout << ceil(1. * a / c) << " " << ceil(1. * b / d) << "\n";
        }
    }
}