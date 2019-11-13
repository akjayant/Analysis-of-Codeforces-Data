#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    if(s==t) {
        cout << "Yes\n";
        return;
    }

    vector<int> mismatch;
    for(int i=0;i<n;i++) if(s[i]!=t[i]) {
        mismatch.push_back(i);
    }

    if(mismatch.size()==1 || mismatch.size()>2) {
        cout << "No\n";
    } else {

        swap(s[mismatch[0]],t[mismatch[1]]);
        
        if(s==t) cout << "Yes\n";
        else cout << "No\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }


    return 0;
}