#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int coun_a = (a + c - 1) / c;
        int coun_b = (b + d - 1) / d;
        cout << (coun_a + coun_b <= k ? (to_string(coun_a) + " " + to_string(coun_b)) : "-1") << "\n";
    }
    return 0;
}