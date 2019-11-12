#include<bits/stdc++.h>
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto cnt = 0;
    auto diff1 = -1, diff2 = -1;
    for(auto i = 0; i < n; ++i)
        if(s[i] != t[i]) {
            if(diff1 == -1)
                diff1 = i;
            else
                diff2 = i;
            cnt++;
        }
    
    if(cnt == 0 || cnt == 2 && s[diff1] == s[diff2] && t[diff1] == t[diff2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    for(auto i = 0; i < t; ++i)
        solve();
}