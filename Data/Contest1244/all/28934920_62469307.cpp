
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = int64_t;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t; cin >>t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = n;
        rep(i,n) {
            if(s[i]=='1') ans = max(ans,2*(i+1));
            if(s[i]=='1') ans = max(ans,2*(n-i));
        }
        cout << ans << endl;
    }

    return 0;
}

