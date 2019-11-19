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
        int n;
        string s;
        cin >> n >> s;
        int minn = 1001;
        for (int j = 0; j < n; j++){
            if (s[j] == '1')
                minn = min(minn, min(j + 1, n - j));
        }
        if (minn == 1001) cout << n << "\n";
        else cout << (n - minn + 1) * 2 << "\n";
    }
    return 0;
}