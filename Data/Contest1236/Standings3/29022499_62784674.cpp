#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int first = min(b, c/2);
        b -= first;
        int second = min(a, b/2);
        cout << (first+second)*3 << endl;
    }

    return 0;
}
