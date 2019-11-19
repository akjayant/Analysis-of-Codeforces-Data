#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                int tmp = max(i+1, n-i) * 2;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}