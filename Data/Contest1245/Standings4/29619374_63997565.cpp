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
 
int gcd(int big, int small) {
    if (big % small ==0) return small;
    else return gcd (small, big% small);
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (gcd(a, b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
    return 0;
}
