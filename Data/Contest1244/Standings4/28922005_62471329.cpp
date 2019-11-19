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
        int n;
        string s;
        cin >> n >> s;
        int ans = n;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                int p_ans = max((i + 1) * 2, (n - i) * 2);
                ans = max(ans, p_ans);
            }
        }
        cout << ans << "\n";
    }
}