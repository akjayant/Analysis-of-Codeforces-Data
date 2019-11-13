#include <iostream>
#include <algorithm>
#include <set>
#include "vector"
#include "queue"
#include <math.h>

using namespace std;

int main() {
    int k, n;
    vector<int> a;
    cin >> k;
    for (int q = 0; q < k; q++) {
        a.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a.push_back(b);
        }
        sort(a.begin(), a.end());
        int count = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] <= count)
                break;
            count++;
        }
        cout << count << "\n";
    }

}
