#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        int d[1001];
        for(int i=1; i<=n; i++) {
            cin >> d[i];
        }

        sort(d+1, d+1+n, greater<int>());

        int j = n;
        for(int i=1; i<=n; i++) {
            if(d[i] < i) {
                j = i - 1;
                break;
            }
        }
        cout << j << '\n';
    }
    return 0;
}