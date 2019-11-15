#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--) {
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        vector<tuple<int, int> > ops;
        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                auto it = find(begin(s)+i+1, end(s), t[i]);
                if(it != end(s)) {
                    int j = it-begin(s);
                    swap(s[j], t[j]);
                    ops.emplace_back(j,j);
                    swap(s[i], t[j]);
                    ops.emplace_back(i,j);
                } else {
                    it = find(begin(t)+i+1, end(t), t[i]);
                    if(it != end(t)) {
                        int j = it-begin(t);
                        swap(s[i], t[j]);
                        ops.emplace_back(i,j);
                    } else {
                        ans = false;
                    }
                }
            }
        }
        if(ans) {
            cout<<"Yes\n";
            if(size(ops) == 0) {
                ops.emplace_back(0,0);
            }
            cout<<size(ops)<<"\n";
            for(auto [a, b] : ops) {
                cout << 1+a << " " << 1+b << "\n";
            }
        } else {
            cout << "No\n";
        }
    }
}
