#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while( T-- ) {
        int n;
        string s, t; 
        cin >> n >> s >> t;
        int cnt = 0;
        int v[2] = {0,0};
        if( s.size() == t.size() ) {
            for( int i = 0; i < n; i++ ) {
                if( s[i] != t[i] ) {
                    if( cnt == 2 ){
                        cnt++;
                        break;
                    }
                    v[cnt] = i;
                    cnt++;
                }
            }
            if( cnt == 2 && s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]] ) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}