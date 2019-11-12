#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << j * n + (j & 1 ? n-i : i+1) << (j < n-1 ? ' ' : '\n');
        }
    }
    return 0;
}