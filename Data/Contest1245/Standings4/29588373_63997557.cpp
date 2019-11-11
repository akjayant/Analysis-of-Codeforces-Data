#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 1001;
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        int a, b;
        cin >> a >> b;
        bool ans = false;
        for (int i = 2; i <= a; ++i) {
            if (a % i == 0 && b % i == 0) {
                ans = true;
            }
        }
        if (ans) {
            cout << "Infinite";
        } else {
            cout << "Finite";
        }
        cout << "\n";
    }

    return 0;
}
